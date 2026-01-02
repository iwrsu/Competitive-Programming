import os
import re
import requests
import shutil

CF_API = "https://codeforces.com/api/problemset.problems"

def normalize(name):
    return re.sub(r'[^a-z0-9]', '', name.lower())

print("Fetching Codeforces problemset...")
resp = requests.get(CF_API).json()

if resp["status"] != "OK":
    print("CF API failed. Life is pain.")
    exit(1)

problems = resp["result"]["problems"]

# Build lookup: normalized problem name -> contestId
lookup = {}
for p in problems:
    if "contestId" in p:
        key = normalize(p["name"])
        lookup[key] = p["contestId"]

for file in os.listdir("."):
    if not file.endswith(".cpp"):
        continue

    # Example: B_Trees_in_a_Row.cpp -> Trees in a Row
    raw_name = file.split("_", 1)[-1].rsplit(".", 1)[0]
    norm_name = normalize(raw_name)

    if norm_name not in lookup:
        print(f"Skipping (not found): {file}")
        continue

    contest_id = lookup[norm_name]
    folder = f"CF_{contest_id}"

    os.makedirs(folder, exist_ok=True)
    shutil.move(file, os.path.join(folder, file))

    print(f"Moved {file} -> {folder}/")
