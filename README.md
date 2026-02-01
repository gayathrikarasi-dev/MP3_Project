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

Clone the repository:
git clone https://github.com/your-username/mp3-tag-reader-c.git
cd mp3-tag-reader-c


## Compile the program
gcc mp3_main.c mp3_view.c mp3_edit.c functions.c -o mp3editor


## Run the program
./mp3editor


## Usage

View MP3 tags:
./mp3editor -v sample.mp3


Edit MP3 tags:
./mp3editor -e <tag> sample.mp3


Then view the updated details:
./mp3editor -v sample.mp3


Use `-v` to view ID3 tag information  
Use `-e` to edit ID3 tag information

## Notes

Follow the prompts to enter the MP3 file path and view its metadata.

The project includes a sample MP3 file named `sample.mp3` for testing.  
An additional file named `temp.mp3` is used while editing tag information.  
All modifications are written to the temporary file first.  
After successful editing, the temporary file replaces the original file.  
This approach ensures that the original data remains safe and uncorrupted.

---

## Skills Learned

- C programming with file handling
- Use of structures and pointers
- Reading and interpreting binary data (ID3 tags)
- Console-based user interface design
- Working with multimedia file formats

---

## Dependencies

- GCC or any standard C compiler
## Screenshots

### Help
<img width="838" height="253" alt="image" src="https://github.com/user-attachments/assets/35a67792-0eaa-4a46-9234-06c5e5808439" />


### View
<img width="899" height="251" alt="image" src="https://github.com/user-attachments/assets/a2bbeab4-6a39-4d63-927a-d538ca07966c" />



### Editing
<img width="968" height="131" alt="image" src="https://github.com/user-attachments/assets/9c1a805a-4711-41d4-b881-f11cf9d7b9d2" />


### View After Edit
<img width="911" height="258" alt="image" src="https://github.com/user-attachments/assets/f17c6f4d-0817-4aef-810a-7ff93e852a22" />


---

## Project Structure
mp3-tag-reader-c/
├─ sample.mp3               # Sample MP3 file for testing
├─ temp.mp3                 # Temporary MP3 file used during editing
├─ images/                  # Screenshots or visuals
│   ├─ help.png
│   ├─ view.png
│   ├─ edit.png
│   └─ v_after_edit.png
├─ README.md                # Project description, usage, instructions
└─ .gitignore               # Files/folders to ignore in Git

