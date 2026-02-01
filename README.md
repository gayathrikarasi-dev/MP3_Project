# 🎵 MP3 Tag Reader using C

## 📌 Overview
MP3 Tag Reader is a console-based application developed in C that allows users to view and edit MP3 metadata using the ID3 tag format. The program reads information such as Title, Artist, Album, Year, and Genre from MP3 files and provides a safe mechanism to update these tags without corrupting the original file.

This project highlights strong fundamentals in C programming, file handling, structures, pointers, and binary data processing.

---

## ✨ Features
- View MP3 metadata (ID3 tags)
- Edit MP3 tag information
- Clean and readable console output
- Safe editing using a temporary file mechanism
- Lightweight implementation using pure C

---

## 🛠 Technologies Used
- C Programming
- File Handling
- Structures & Pointers
- Binary File Processing
- GCC Compiler

---

## 🚀 How to Run

### Clone the Repository
```bash
git clone https://github.com/your-username/mp3-tag-reader-c.git
cd mp3-tag-reader-c
Compile the Program
gcc mp3_tag_reader.c -o mp3_tag_reader
Execute the Program
./mp3_tag_reader
📖 Usage
View MP3 Tag Details
./mp3_tag_reader -v sample.mp3
Edit MP3 Tag Details
./mp3_tag_reader -e <tag> sample.mp3
After editing, verify the changes:

./mp3_tag_reader -v sample.mp3
Command Options
-v → View MP3 tag information

-e → Edit MP3 tag information

⚙️ Working Principle
The program reads MP3 metadata directly from binary files.

While editing, changes are written to a temporary file.

After successful editing, the temporary file replaces the original MP3 file.

This ensures data integrity and prevents file corruption.

📁 Project Structure
mp3-tag-reader-c/
│
├── sample.mp3
├── temp.mp3
├── images/
│   ├── help.png
│   ├── view.png
│   ├── edit.png
│   └── view_after_edit.png
├── mp3_tag_reader.c
├── README.md
└── .gitignore
🧠 Skills Gained
C file handling

Binary data processing

Structures and pointers

Command-line application development

Multimedia file format understanding

📋 Requirements
GCC or any standard C compiler

Linux / Unix-based environment

👩‍💻 Author
Karasi Gayathri


---

## ❗ IMPORTANT TIPS (please read)
✔ Paste only inside **README.md**  
✔ Do **not** paste inside “Description” box  
✔ After pasting → scroll down → **Preview** tab  
✔ Then click **Commit changes**

---

If it still doesn’t look right:
👉 Tell me **where you are pasting** (GitHub website / VS Code / terminal)  
👉 Or send me a **screenshot**

I’ll fix it instantly 💙🚀
