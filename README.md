# Roman Numeral Kata in C

To setup a machine:

Install Check:
Check was not in the apt repositories at the time of this writing. To install check, I had to install from sources.

http://check.sourceforge.net/web/install.html#linuxsource

1) Download the latest source: https://sourceforge.net/projects/check/files/latest/download

2) Extract the package to a directory

3) Run these commands:
./configure
make
make check (<-- This step can take several minutes due to testing)
sudo make install

4) Make sure libcheck is in your library path
sudo ldconfig


Install ATOM editor (optional):
I was not happy with vim or emacs so I installed the Atom editor.


To build the project:

1) Go to the project root directory which contains "makefile"
2) Clean the project: make clean
3) Run tests: make test
4) Build kata: make all

To run the project:
./kata
