#!/usr/bin/env python3
"""
organize_cses_debug.py

Usage:
  # dry-run: show debug info for one file (no moving)
  python3 organize_cses_debug.py Apartments.cpp

  # actually move if a best match is found (be careful)
  python3 organize_cses_debug.py Apartments.cpp --move

  # if you don't pass a filename, it picks the first .cpp in cwd
"""
import os, re, sys, shutil, requests
from bs4 import BeautifulSoup
import difflib
import argparse

URL = "https://cses.fi/problemset/"

def normalize(s: str) -> str:
    s = s.lower()
    s = s.replace("_", " ")
    s = re.sub(r"[^a-z0-9 ]", "", s)
    s = re.sub(r"\s+", " ", s).strip()
    return s

def load_problem_mapping():
    html = requests.get(URL).text
    soup = BeautifulSoup(html, "html.parser")
    mapping = {}

    # Try multiple extraction strategies and prefer data-title if present
    for h2 in soup.find_all("h2"):
        category = h2.text.strip().replace(" ", "_")
        container = h2.find_next_sibling("div")
        if not container:
            continue
        for a in container.find_all("a"):
            title = a.get("data-title")
            if not title:
                title = a.text.strip()
            if not title:
                continue
            mapping[normalize(title)] = category
    return mapping

def debug_one_file(filename, mapping, do_move=False):
    if not os.path.exists(filename):
        print(f"[ERROR] file not found: {filename}")
        return

    raw = os.path.splitext(os.path.basename(filename))[0]
    key = normalize(raw)
    print(f"\nFilename: {filename}")
    print(f"Raw name: {raw}")
    print(f"Normalized key: '{key}'\n")

    # Quick stats & sample of mapping keys
    keys = sorted(mapping.keys())
    print(f"Total problems loaded: {len(keys)}")
    print("\nSample scraped problem keys (first 30):")
    for k in keys[:30]:
        print("  ", k)
    print("...\n")

    # Exact match?
    if key in mapping:
        cat = mapping[key]
        print(f"[EXACT MATCH] -> category: {cat}")
        if do_move:
            dst = os.path.join(cat, os.path.basename(filename))
            os.makedirs(cat, exist_ok=True)
            shutil.move(filename, dst)
            print(f"[MOVED] {filename} -> {dst}")
        else:
            print("[DRY-RUN] pass --move to actually move the file")
        return

    # Substring matches
    substr_matches = [k for k in keys if key in k or k in key]
    if substr_matches:
        print("[SUBSTRING MATCHES]")
        for k in substr_matches[:10]:
            print("  ", k, "->", mapping[k])
    else:
        print("[NO substring matches found]")

    # Fuzzy matches using difflib
    close = difflib.get_close_matches(key, keys, n=10, cutoff=0.5)
    if close:
        print("\n[FUZZY MATCHES]")
        for c in close:
            print("  ", c, "->", mapping[c])
    else:
        print("\n[NO fuzzy matches found with cutoff=0.5]")

    # Print top fuzzy with scores
    def score(a, b):
        return difflib.SequenceMatcher(None, a, b).ratio()
    scored = sorted(((k, score(key, k)) for k in keys), key=lambda x: -x[1])[:10]
    print("\nTop 10 similarity scores (key vs scraped):")
    for k, sc in scored:
        print(f"  {sc:.3f}  {k} -> {mapping[k]}")

    # If there's a clear best candidate (score>=0.75), offer to move if --move specified
    best_key, best_score = scored[0]
    if best_score >= 0.75:
        print(f"\nBest candidate: '{best_key}' (score {best_score:.3f}) -> {mapping[best_key]}")
        if do_move:
            dst_dir = mapping[best_key]
            os.makedirs(dst_dir, exist_ok=True)
            dst = os.path.join(dst_dir, os.path.basename(filename))
            shutil.move(filename, dst)
            print(f"[MOVED] {filename} -> {dst}")
        else:
            print("[DRY-RUN] pass --move to actually move the file")
    else:
        print("\nNo confident match (best score < 0.75). Not moving automatically.")

def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("file", nargs="?", default=None, help="Single .cpp filename to debug (in cwd)")
    parser.add_argument("--move", action="store_true", help="Actually move the file if a confident match is found")
    args = parser.parse_args()

    # pick a file if none given
    filename = args.file
    if filename is None:
        # find first .cpp in cwd
        files = [f for f in os.listdir(".") if f.endswith(".cpp")]
        if not files:
            print("No .cpp files in current directory.")
            return
        filename = files[0]
        print(f"No filename given. Using first .cpp: {filename}")

    mapping = load_problem_mapping()
    debug_one_file(filename, mapping, do_move=args.move)

if __name__ == "__main__":
    main()
