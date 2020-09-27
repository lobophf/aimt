# Contributing to Aimt

First off, thanks for your interest in contributing to Aimt! We appreciate the contributions of all types. 
See the table of contents for different ways to help and details about this project. These are mostly guidelines, 
not rules. So, use your best judgment, and feel free to propose changes, including in this document.

#### Table Of Contents
[What should I know before I get started?](#what-should-i-know-before-i-get-started)

[How Can I Contribute?](#how-can-i-contribute)
* [Reporting Bugs](#reporting-bugs)
* [Developing Aimt](#developing-aimt)

[Styleguides](#styleguides)
* [Git Commit Messages](#git-commit-messages)


## What should I know before I get started?
The Aimt is an array index mapping tool. This is an open-source project that contains two main functions 
ind2sub and sub2ind, which interconvert between index and subscripts. This simple tool was designed to be 
incorporated into C codes, and therefore is compatible with C++ as well. 

## How Can I Contribute?
### Reporting bugs
If you run into an error or bug with the project:
* Open an Issue at https://github.com/lobophf/aimt/issues
* Include reproduction steps that someone else can follow to recreate the bug or error on their own.
* Provide details like operating system and compiler versions.

### Developing Aimt
So you wanna contribute! Awesome! This project uses GitHub to manage contributions, so you can fork this repository, make your changes, push your changes in a side branch, and finally create a pull request.

## Styleguides
### Git Commit Messages
To write commits messages, it would be nice if you used the template available in this repository. You can easily configure it using the command below:
```
$ git config --local commit.template docs/.git-commit-template.txt
```
So, when you create a commit, don't use the "-m" or "--message" option. Just type the command below and wait for your editor to open. The template file contains other instructions. When you finished, save and close the file.
```
$ git commit
```
