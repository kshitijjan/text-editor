<div align="center">

# Text Editor

</div>


<div align="center">

## Table of Contents

- [How to Run the Code](#how-to-run-the-code)
- [What Has Been Done](#what-has-been-done)
- [Issues/Challenges](#issueschallenges)
- [Features](#features)

</div>

---

## How to Run the Code

Please follow the instructions below to run the code:

1. Clone this repository  ``` git clone https://github.com/kshitijjan/text-editor.git ```
2. Download Qt Creator on your machine. Before downloading make sure you have selected the correct operating system [Link to download](https://www.qt.io/download-qt-installer-oss?hsCtaTracking=99d9dd4f-5681-48d2-b096-470725510d34%7C074ddad0-fdef-4e53-8aa8-5e8a876d6ab4)
3. Open Qt Creator and click Open Project
4. Now, locate the folder where you cloned the project
5. Open ``` CMakeLists.txt ``` file. This will open the entire project in your Qt creator
6. Finally RUN the project by clicking on the run button located at the bottom left corner

---

## What Has Been Done

In this project, we have accomplished the following:

- This is a text editor with all the basic functions like Cut, Paste, Copy Undo, Redo, Open any text document, Save, Save as, etc
- While writing on this text editor you can bold/unbold individual text
- If you want to write anything with Superscript or Subscript, it can be easily possible by selecting the text and clicking on the respective button.
- The application will open in the same theme as on your PC. Eg: Light Mode or Dark Mode
  
- Overview of functionalities added
  ![Screenshot 2023-06-21 at 6 55 01 PM](https://github.com/kshitijjan/text-editor/assets/64248758/670280f7-52fc-49b4-a28f-23bce4d3c938)

---

## Issues/Challenges

During the development of this project, I encountered the following issues/challenges:

The biggest issue I faced is downloading the Qt Creator. There was some connection issue from the server side so it was downloading at the speed of ~200kbps, no matter how fast your internet is. And after downloading around 300 MB the downloading automatically fails. So I thought there is some issue with MacOS files. So I created a Virtual Machine and installed Ubuntu and Windows but still had the same issue with both operating systems as well. I downloaded this software around 20 times and faced the same error each time.
- How I resolved this issue?
I downloaded individual packages for the file which had created this issue.
- In Qt Creator, if you are building a project in CMake, if you add resources like PDFs and logos then you have to create a .qrc file. Also, the resources file is not directly added just like VS Code or any other IDE, you get a path of the added resources.qrc file and you have to manually add that path to CMakeLists.txt. This issue took around 2-3 hours to solve because this was my first time using Qt Creator.

- But I learnt a lot while building this project :)

---

## Features

The key features of this project include:

- Create a New file
- Open a file
- Cut
- Copy
- Paste
- Undo
- Redo
- Save
- Save as
- Bold/Unbold
- Superscript individual text
- Subscript individual text
- Added resumé in the About Me section
