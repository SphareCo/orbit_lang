import os

folder_name = "tests_v0.5"

if not os.path.exists(folder_name):
    os.makedirs(folder_name)

files = {
    "01_hello.orb": """
// Test 1: Basic Print
bolo "Namaste Orbit!";
print "Hello World from English keyword";
""",

    "02_variables.orb": """
// Test 2: Variables
manlo name = "Orbit Language";
let version = 0.5;

bolo "Language Name:";
bolo name;
bolo "Current Version:";
print version;
""",

    "03_math_simple.orb": """
// Test 3: Simple Math
manlo a = 100;
let b = 50;

bolo "Addition (100 + 50):";
bolo a + b;

bolo "Subtraction (100 - 50):";
bolo a - b;
""",

    "04_bodmas.orb": """
// Test 4: BODMAS Precedence
// Rule: Divide/Multiply pehle, Plus/Minus baad mein
// 10 + 5 * 2 = 20 aana chahiye (Not 30)

manlo result = 10 + 5 * 2;
bolo "BODMAS Check (Expect 20):";
bolo result;

let complex = 100 - 50 / 2; 
// 100 - 25 = 75
bolo "Division Check (Expect 75):";
bolo complex;
""",

    "05_logic_if.orb": """
// Test 5: Basic Conditions
manlo marks = 80;

agar (marks) {
    bolo "Student Pass hai!";
} warna {
    bolo "Student Fail hai.";
}
""",

    "06_nested_logic.orb": """
// Test 6: Nested If/Else
let age = 20;
let hasId = sahi; // true

agar (age) {
    bolo "Age is valid.";
    
    agar (hasId) {
        bolo "Entry Granted (ID bhi hai).";
    } warna {
        bolo "Entry Denied (ID missing).";
    }
}
""",

    "07_blocks_scope.orb": """
// Test 7: Blocks and Scope
manlo x = 10;

agar (x) {
    // New Scope
    manlo x = 99;
    bolo "Inside Block x is (Expect 99):";
    bolo x;
}

bolo "Outside Block x is (Expect 10):";
bolo x;
""",

    "08_mixed_lang.orb": """
// Test 8: Hindi English Mix
let a = 10;
manlo b = 20;

agar (a) {
    print "English If works with Hindi Variable";
    bolo b;
}
""",

    "09_comments.orb": """
// Test 9: Comments Check
manlo x = 10;
// manlo x = 50;  <-- Ye line run nahi honi chahiye

bolo "Value should be 10:";
bolo x;
""",

    "10_final_stress.orb": """
// Test 10: Final Boss (Maths + Logic + Mix)
manlo basic = 1000;
let tax = 100;
let isRich = sahi;

let total = basic + tax * 2; 
// 1000 + 200 = 1200

agar (isRich) {
    bolo "Rich Person Total:";
    bolo total;
} warna {
    bolo "Normal Total:";
    bolo basic;
}
"""
}

for filename, content in files.items():
    path = os.path.join(folder_name, filename)
    with open(path, "w") as f:
        f.write(content.strip())

print(f"Success! 10 test files '{folder_name}' folder mein aa gayi hain.")



# .\build\orbit.exe tests_v0.5\01_hello.orb
# .\build\orbit.exe tests_v0.5\04_bodmas.orb
# .\build\orbit.exe tests_v0.5\09_comments.orb