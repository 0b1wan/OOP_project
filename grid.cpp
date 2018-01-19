#include "block.cpp"

class Grid
{
    private:
        Block *** blockarray;
        int columns;
        int rows;
    public:
        Grid(int c, int r) : columns(c), rows(r)
        {
            blockarray=new Block**[rows];
            for (int i=0; i<rows; i++)
            {
                blockarray[i]=new Block*[columns];
            }
            //read from GRID FILE columns*rows blocks (their properties), create the block objects in the heap and pass their addresses in the array
            for (int i=0; i<columns; i++)
            {
                for (int j=0; j<rows; j++)
                {
                    //read the GRID FILE and use "new" for each on of them and then pass their addresses to blockarray[i][j]
                }
            }
        }
        ~Grid()
        {
            //deallocate the array in heap
            for (int i=0; i<columns; i++)
            {
                for (int j=0; j<rows; j++)
                {
                    delete blockarray[i][j]; //delete the blocks
                }
            }
            
            for (int i=0; i<rows; i++)
            {
                delete[] blockarray[i]; //delete all the rows
            }
            
            delete[] blockarray;
        }
        void displaymap()
        {
            
        }
};