import os
import shutil

# Hard-coded CSES mapping for your current files
PROBLEM_TO_CATEGORY = {
    "Apartments": "Sorting_and_Searching",
    "Bit_Strings": "Introductory_Problems",
    "Coin_Piles": "Introductory_Problems",
    "Collecting_Numbers": "Sorting_and_Searching",
    "Collecting_Numbers_II": "Sorting_and_Searching",
    "Concert_Tickets": "Sorting_and_Searching",
    "Distinct_Numbers": "Sorting_and_Searching",
    "Distinct_Values_Subarrays": "Sorting_and_Searching",
    "Dynamic_Range_Sum_Queries": "Range_Queries",
    "Factory_Machines": "Sorting_and_Searching",
    "Ferris_Wheel": "Sorting_and_Searching",
    "Gray_Code": "Introductory_Problems",
    "Josephus_Problem_I": "Mathematics",
    "Maximum_Subarray_Sum": "Sorting_and_Searching",
    "Missing_Coin_Sum": "Sorting_and_Searching",
    "Movie_Festival": "Sorting_and_Searching",
    "Number_Spiral": "Introductory_Problems",
    "Palindrome_Reorder": "Introductory_Problems",
    "Playlist": "Sorting_and_Searching",
    "Range_Xor_Queries": "Range_Queries",
    "Repetitions": "Introductory_Problems",
    "Restaurant_Customers": "Sorting_and_Searching",
    "Room_Allocation": "Sorting_and_Searching",
    "Static_Range_Minimum_Queries": "Range_Queries",
    "Static_Range_Sum_Queries": "Range_Queries",
    "Stick_Lengths": "Sorting_and_Searching",
    "Trailing_Zeros": "Introductory_Problems",
    "Two_Knights": "Introductory_Problems",
    "Two_Sets": "Introductory_Problems",
}

moved = 0
skipped = 0

for file in os.listdir("."):
    if not file.endswith(".cpp"):
        continue

    name = file.replace(".cpp", "")

    if name not in PROBLEM_TO_CATEGORY:
        print(f"SKIP  : {file}")
        skipped += 1
        continue

    folder = PROBLEM_TO_CATEGORY[name]
    os.makedirs(folder, exist_ok=True)
    shutil.move(file, os.path.join(folder, file))
    print(f"MOVED : {file} -> {folder}/")
    moved += 1

print("\nDone.")
print(f"Moved   : {moved}")
print(f"Skipped : {skipped}")
