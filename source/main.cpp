/*
N Dimensional Arrays
(c) 2016
Author: David Erbelding
Written under the supervision of David I. Schwartz, Ph.D., and
supported by a professional development seed grant from the B. Thomas
Golisano College of Computing & Information Sciences
(https://www.rit.edu/gccis) at the Rochester Institute of Technology.
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or (at
your option) any later version.
This program is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
General Public License for more details.
You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/



// Include iostream for output during the program.
#include <iostream>
// Use std to avoid writing std:: everywhere.
using namespace std;


// Start of main function
int main() 
{
    // Say you want to store a table of information that looks like this:
    //  
    //  +---+---+---+---+
    //  |  0|  0|  1|  0|
    //  +---+---+---+---+
    //  |  1|  1|  1|  0|
    //  +---+---+---+---+
    //  |  0|  1|  0|  1|
    //  +---+---+---+---+
    //  |  0|  1|  1|  0|
    //  +---+---+---+---+
    //
    {

        // Create the array with the information we want.
        int grid[16] = {
            0, 0, 1, 0,
            1, 1, 1, 0,
            0, 1, 0, 1,
            0, 1, 1, 0
        };  // Note: I could have written this all in one line, but that would be ugly and unreadable.
            // This way looks nice and is easy to understand.
            // Don't be the person who fills a 2d array in a single line.



        // We can index into the array with numbers 0 - 15.
        cout << "printing array as 1 dimensional." << endl;
        for (int i = 0; i < 16; i++)
        {
            cout << grid[i] << endl;
        }

        // OR, we can index into the array with 2 dimensions!
        cout << "printing array as 2 dimensional." << endl;
        for (int i = 0; i < 4; i++)             // Loop over rows
        {
            int rowOffset = i * 4;              // Each row starts further into the array.

            for (int j = 0; j < 4; j++)         // Loop across each element in the row.
            {
                int index = rowOffset + j;      // Get the index of our element by offseting down to the beginning of the row, and then across.

                cout << grid[index] << " ";     // Print out the element we want, followed by a space.

                //      Alternatively just do this and recalculate the index every time
                //  cout << grid[i * 4 + j] << " ";
                //      This is slower, but if you really wanted to be faster you would just do it the first way with 1 loop.
            }
            cout << endl;                       // At the end of a row, go to the next line.
        }
    }
    cin.get();


    {
        // Now that you know how a 2d array works, there's a better way.
        // C++ has a built in feature for multi dimensional arrays that manages the annoying parts for you.

        // Just create your array like this:
        int grid[4][4] = {
            0, 1, 2, 3,
            3, 0, 1, 2,
            2, 3, 0, 1,
            1, 2, 3, 0
        };

        // Let's test it out:
        cout << "Element access:" << endl;
        cout << "grid[1][0]: " << grid[1][0] << endl;   // You may be expecting this to print 1, but it actually prints 3.
        cin.get();                                      // This is because the first value is the row, and the second value is the column
        
        // Looping to print the array is easy:
        cout << "2D style iteration: " << endl;

        for (int i = 0; i < 4; i++)             // Loop over rows
        {
            for (int j = 0; j < 4; j++)         // Loop across each element in the row.
            {
                // Print out the element.
                cout << "grid[" << i << "][" << j << "]: " << grid[i][j] << endl;
            }
            cout << endl;                       // At the end of a row, go to the next line.
        }

        cin.get();

        // Underneath, this array works exactly the same as the previous one:
        // Proof?
        // We can actually just loop through the array with only the second value, and get the same output:
        cout << "1D style iteration still possible: " << endl;
        for (int i = 0; i < 16; i++)
        {
            cout << "grid[0][" << i << "]: " << grid[0][i] << endl;
        }
    }
    cin.get();


    {
        // Finally, an example with a more than 2 dimensional array.

        //      Arrays can stack of as many dimensions as you'd like:
        // int hugeFiveDimensionArray[16][16][16][16];

        // Be careful though, this can stack up in size really quickly.
        // This example is 16^4 = 65536 integers.
        // That's 256 kilobytes of ram with one line of code!


        cout << "Creating 4d Array" << endl;
        int fiveDimensionArray[4][4][4][4];     // A 4d array of 256 integers. (only 1 kb of ram)

        cout << "Filling Array" << endl;
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                for (int k = 0; k < 4; k++)
                {
                    for (int l = 0; l < 4; l++)
                    {
                        fiveDimensionArray[i][j][k][l] = (i + j + k + l) % 4;
                    }
                }
            }
        }

        cout << "Printing Array:";

        for (int i = 0; i < 4; i++)
        {
            cout << endl;       // new line every 64 numbers

            for (int j = 0; j < 4; j++)
            {
                cout << endl;   // new line every 16 numbers

                for (int k = 0; k < 4; k++)
                {
                    // Add spacing every 4 numbers
                    cout << "  ";

                    for (int l = 0; l < 4; l++)
                    {
                        // Print out one number with a space
                        cout << fiveDimensionArray[i][j][k][l] << " ";
                    }
                }
            }
        }

        cout << "\n\nDone." << endl;



        cin.get();

        // What if I want to only use a subset of the data?
        // Just change where you begin and end iterating over the data:

        cout << "Printing Subset of Data:";

        for (int i = 0; i < 4; i++)
        {
            cout << endl;       // new line every 64 numbers

            for (int j = 0; j < 3; j++)
            {
                cout << endl;   // new line every 16 numbers

                for (int k = 0; k < 4; k++)
                {
                    // Add spacing every 4 numbers
                    cout << "  ";

                    for (int l = 0; l < 3; l++)
                    {
                        // Print out one number with a space
                        cout << fiveDimensionArray[i][j][k][l] << " ";
                    }
                }
            }
        }

        cout << "\n\nDone." << endl;




    }
    cin.get();


    return 0;   // End Program.
}