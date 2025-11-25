# Orbit Programming Language

> **Version:** 0.2 (The Lexer Engine)  
> **Developed by:** Sphare Co.  
> **Status:** Active Development

**Orbit** is a futuristic, dual-language programming language built from scratch using C++. It is designed to bridge the gap between English and Hindi speakers by allowing code to be written in either language (or a mix of both).

---

## 🚀 Key Features (v0.2)

- **Dual Keyword System:** Write code in **English** or **Hindi**.
- **Custom Lexer:** Built-in Tokenizer to process source code efficiently.
- **Lightweight:** Written in core C++ for high performance.

### Keyword Mapping
| Token Type | English Keyword | Hindi Keyword |
| :--- | :--- | :--- |
| Variable | `let` | `manlo` |
| Print | `print` | `bol` |
| Condition | `if` | `agar` |
| Else | `else` | `warna` |

---

## 📂 Project Structure

```text
Orbit_Lang/
├── docs/            # Documentation website
├── examples/        # Example scripts (.orb files)
├── include/         # Header files (.h)
├── src/             # Source code (.cpp)
└── README.md        # This file
```

## 🛠️ How to Build & Run

To run Orbit on your machine, you need a C++ compiler (like G++).

**Step 1: Navigate to Source :**
Open your terminal/command prompt and go to the `src` folder:

```sh
cd src
```
**Step 2: Compile the Engine :**
    Run the following command to compile the `Lexer` and `Main controller`:

```sh 
g++ main.cpp Lexer.cpp -o orbit
```
(This will create an executable file named `orbit.exe`)

**Step 3: Run a Script :**
    Execute the example script provided in the examples folder:

```sh
./orbit ../examples/test.orb
```

### 📝 Example Code (test.orb)

**Plaintext**
```sh
manlo name = "SphareCo";
bol name;
let x = 2;
print x;
```
### Output:

**Plaintext**
```
---Orbit Lexer Output(Tokens)---
Token ID: 1 || Token value: manlo
Token ID: 4 || Token value: name
Token ID: 7 || Token value: =
Token ID: 6 || Token value: SphareCo
Token ID: 12 || Token value: ;
Token ID: 4 || Token value: bol
Token ID: 4 || Token value: name
Token ID: 12 || Token value: ;
Token ID: 1 || Token value: let
Token ID: 4 || Token value: x
Token ID: 7 || Token value: =
Token ID: 5 || Token value: 2
Token ID: 12 || Token value: ;
Token ID: 0 || Token value: print
Token ID: 4 || Token value: x
Token ID: 12 || Token value: ;
Token ID: 13 || Token value: 
...
```