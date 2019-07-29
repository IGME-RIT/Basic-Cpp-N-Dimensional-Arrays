Documentation Author: Niko Procopi 2019

This tutorial was designed for Visual Studio 2017 / 2019
If the solution does not compile, retarget the solution
to a different version of the Windows SDK. If you do not
have any version of the Windows SDK, it can be installed
from the Visual Studio Installer Tool

Welcome to the Multi-Dimensional Arrays Tutorial!
Prerequesites: Dynamic Arrays

Before we start explaining the tutorial, I want one thing to be clear,
when we say "Multi-dimensional", we are not talking about time travel paradoxes,
or any Rick & Morty nonsense. "Multi-dimensional" simply means "arrays of arrays".

This is a one-dimensional array, one list of 10 numbers.
	int numbers[10];

This is a two-dimensional array, one list, of 10 lists, 
of 10 numbers, totalling 100 numbers
	int numbers[10][10];

This is a three-dimensional array, one list, of 10 lists, 
of 10 lists, of 10 numbers, totalling 1000 numbers
	int numbers[10][10][10];
	
You can make as many dimensions as you want. 
There is no limit,  unless you run out of RAM
