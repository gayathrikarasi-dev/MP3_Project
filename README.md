# MP3 Tag Reader using C

## Overview
MP3 Tag Reader is a console-based application developed in C that allows users to view and edit metadata from MP3 files using the ID3 tag format. The program displays information such as title, artist, album, year, and genre, and provides a safe mechanism to modify tag data without corrupting the original file.

This project demonstrates a strong understanding of C programming fundamentals, including file handling, structures, pointers, and binary data processing.

---

## Features
- Read MP3 metadata (ID3 tags)
- Edit MP3 tag information
- Display metadata in a clear console format
- Use a temporary file to ensure data safety
- Lightweight implementation using pure C

---

## Technologies Used
- C Programming
- File Handling
- Structures and Pointers
- Binary File Processing
- GCC Compiler
## How to Run

### Clone the Repository
```bash
git clone https://github.com/your-username/mp3-tag-reader-c.git
cd mp3-tag-reader-c
Compile the Program
gcc mp3_main.c mp3_view.c mp3_edit.c functions.c -o mp3editor
Run the Program
./mp3editor
Usage
View MP3 Tag Information
./mp3editor -v sample.mp3
Edit MP3 Tag Information
./mp3editor -e <tag> sample.mp3
After editing, view the updated details:

./mp3editor -v sample.mp3
Options
-v : View MP3 tag information

-e : Edit MP3 tag information

Notes
The project includes a sample MP3 file named sample.mp3 for testing.

A temporary file is used while editing tag information.

After successful editing, the temporary file replaces the original file.

This method ensures that the original data is not corrupted during modification.

Skills Learned
C programming with file handling

Use of structures and pointers

Reading and interpreting binary data

Command-line based application development

Understanding MP3 metadata formats

Dependencies
GCC or any standard C compiler

Project Structure
mp3-tag-reader-c/
│
├── sample.mp3
├── temp.mp3
├── images/
│   ├── help.png
│   ├── view.png
│   ├── edit.png
│   └── view_after_edit.png
├── mp3_main.c
├── mp3_view.c
├── mp3_edit.c
├── functions.c
├── mp3_header.h
├── README.md
└── .gitignore
Author
Karasi Gayathri
ECE Graduate | C Programming and Embedded Systems

---

