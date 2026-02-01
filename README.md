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

---

## How to Compile and Run

### Compile the Program
```bash
gcc mp3_main.c mp3_view.c mp3_edit.c functions.c -o mp3editor
Run the Program
./mp3editor
Usage
View MP3 Tag Information
./mp3editor -v sample.mp3
Edit MP3 Tag Information
./mp3editor -e <tag> sample.mp3
After editing, verify the updated information:

./mp3editor -v sample.mp3
Command Options
-v : View MP3 tag information

-e : Edit MP3 tag information

Working Principle
The program reads metadata directly from MP3 binary files. During editing, changes are written to a temporary file. After successful modification, the temporary file replaces the original MP3 file. This approach ensures data integrity and prevents accidental file corruption.

Project Structure
250046H_MP3_Project/
│
├── mp3_main.c
├── mp3_view.c
├── mp3_edit.c
├── functions.c
├── mp3_header.h
├── sample.mp3
├── MP3_TAG_READER.pdf
├── .gitignore
└── README.md
Skills Gained
Practical experience with C file handling

Working with binary data formats

Modular programming using multiple source files

Use of structures and pointers

Command-line application development

Requirements
GCC or any standard C compiler

Linux or Unix-based environment

Author
Karasi Gayathri
ECE Graduate | Embedded Systems and C Programming


---

### Why this version is better
- Fully human-written tone  
- No icons or emojis  
- Clean professional language  
- ATS and recruiter friendly  
- Proper GitHub Markdown formatting  

You’re doing this the **right way**.  
If you want, I can also:
- Review your **code structure**
- Optimize `.gitignore`
- Write a **LinkedIn post** in the same human tone

Just tell me 👍
