#include "grid.hpp"


Grid::Grid(int row, int col)
{
    columns = col;
    rows = row;

    Blocks=new Block**[rows];
    for (int c=0; c<columns; c++)
    {
        Blocks[c]=new Block*[columns];
    }

    for (int r=0; r<rows; r++)
    {
        for (int c=0; c<columns; c++)
        {

            Blocks[r][c] = new class Common(r, c);
        }
    }
    theMap = new class Map();
    createVisualMap();
}

int Grid::createVisualMap()
{

    // Create visual map...

    // First Line
    theMap->add_textbox(theMap->HorizontalBlock1, -1, true);
    for (int i=0; i<columns-2; i++)
        theMap->add_textbox(theMap->HorizontalBlock2);
    theMap->add_textbox(theMap->HorizontalBlock3);

    // In-Between Rows...
    for (int r=0; r<rows; r++) {
        // First Textbox
        theMap->add_textbox(theMap->VerticalBlock,-1, true);
        if (Blocks[r][0]->block_type == "Common") {
            if(!Blocks[r][0]->hasHeros())
                theMap->add_textbox(theMap->EmptyBlock);
            else
                theMap->add_textbox(theMap->HerosBlock(Blocks[r][0]->heros));
        }
        else if (Blocks[r][0]->block_type == "Market")
            theMap->add_textbox(theMap->MarketBlock);
        else
            theMap->add_textbox(theMap->NonAccessibleBlock);

        // All other Textboxes
        for (int c=1; c<columns; c++) {
            theMap->add_textbox(theMap->VerticalBlock);
            if (Blocks[r][c]->block_type == "Common") {
                if(!Blocks[r][c]->hasHeros())
                    theMap->add_textbox(theMap->EmptyBlock);
                else
                    theMap->add_textbox(theMap->HerosBlock(Blocks[r][c]->heros));
            }
            else if (Blocks[r][c]->block_type == "Market")
                theMap->add_textbox(theMap->MarketBlock);
            else
                theMap->add_textbox(theMap->NonAccessibleBlock);
        }
        theMap->add_textbox(theMap->VerticalBlock);

        // Middle Line
        if (r == rows-1)
            break;
        theMap->add_textbox(theMap->HorizontalBlock4, -1, true);
        for (int i=0; i<columns-2; i++)
            theMap->add_textbox(theMap->HorizontalBlock1);
        theMap->add_textbox(theMap->HorizontalBlock5);
    }



    // Last Line
    theMap->add_textbox(theMap->HorizontalBlock1, -1, true);
    for (int i=0; i<columns-2; i++)
        theMap->add_textbox(theMap->HorizontalBlock2);
    theMap->add_textbox(theMap->HorizontalBlock3);

    return 0;
}

int Grid::updateVisualMap()
{
//    for (int r=0; r<rows; r++)
//    {
//        for (int c=0; c<columns; c++)
//        {
//            if (Blocks[c][r]->block_type == "Common") {
//                if(Blocks[c][r]->heroCount() <= 0) {
//
//                    theMap->blocks[r][c] = theMap->EmptyBlock;
//                }
//                    else
//                    theMap->blocks[r][c] = theMap->HerosBlock(Blocks[c][r]->heros);
//            }
//            else if (Blocks[c][r]->block_type == "Market")
//                theMap->blocks[r][c] = theMap->MarketBlock;
//            else
//                theMap->blocks[r][c] = theMap->NonAccessibleBlock;
//        }
//    }

    //theMap->blocks[1][3] = theMap->MarketBlock;
    return 0;
}

Grid::~Grid()
{

    //deallocate the array in heap
    for (int i=0; i<columns; i++)
    {
        for (int j=0; j<rows; j++)
        {
            delete Blocks[i][j]; //delete the blocks
        }
    }

    for (int i=0; i<rows; i++)
    {
        delete[] Blocks[i]; //delete all the rows
    }

    delete[] Blocks;

}
int Grid::add_Market(int x, int y)
{
    delete Blocks[x][y];
    Blocks[x][y] = new class Market(x,y);
    return 0;
}

int Grid::add_NonAccessible(int x, int y)
{
    delete Blocks[x][y];
    Blocks[x][y] = new class NonAccessible(x,y);
    return 0;
}


void Grid::showMap()
{
    delete theMap;
    theMap = new Map();
    createVisualMap();
    theMap->show();
}

/* DO NOT MESS WITH FUNCTION. IT WORKING IS A MIRACLE,
   THAT HAPPENED AFTER HOURS OF PRAYING TO THE 12 GODS OF OLYMPUS */
void Map::show()
{
    // for each row
    for (int r=0; r<blocks.size(); r++) {
        // find maximum text lines in r row
        int max_lines=0;
        for (int i=0; i<blocks[r].size(); i++) {
            if (max_lines < blocks[r][i]->lines)
                max_lines = blocks[r][i]->lines;
        }

        // print each line
        for (int l=0; l<max_lines; l++) {
            // print l line of each textbox in r row
            for (int j=0; j<blocks[r].size(); j++) {
                if (blocks[r][j]->lines < l+1)
                    for (int s=0; s<blocks[r][j]->text[l-1].size(); s++)
                        cout << " ";
                else {
                    cout << blocks[r][j]->text[l];
                    if ((l>0) && blocks[r][j]->text[l].size() < blocks[r][j]->text[l-1].size()) {
                        int difference = (int)blocks[r][j]->text[l-1].size() - (int)blocks[r][j]->text[l].size();
                        for (int d=0; d<difference; d++)
                            cout << " ";
                    }
                }
            }
            cout << endl;
        }
    }

}


void Map::add_textbox(class Textbox* textbox, int charLimit, bool newline)
{

    if (charLimit == -1)
        charLimit = (int)textbox->text[0].size();

    for (int i=0; i<textbox->lines; i++) {
        if (textbox->text[i].size() > charLimit)
            textbox->text[i].erase(charLimit, textbox->text[i].size());
    }
    
    if (newline) {
        vector<Textbox*> myvector;
        myvector.push_back(textbox);
        blocks.push_back(myvector);
    }
    else
        blocks[blocks.size()-1].push_back(textbox);
}


Textbox::Textbox(vector<string> txt, string type)
{
    box_type = type;

    lines = (int)txt.size();
    for (int i=0; i<lines; i++)
        text.push_back(txt[i]);
}



class Textbox* Map::HerosBlock(vector<class Hero*> heros) {

    class Textbox* myblock = nullptr;

    vector<string> text;

    for (int i=0; i<heros.size(); i++) {
        std::ostringstream thestring;
        thestring << heros[i]->hero_type.at(0) << ":";
        if (heros[i]->health < 0)
            thestring << "DEAD";
        else {
            if((int)(((float)heros[i]->health/heros[i]->max_health)*100) < 10)
                thestring << "  " << (int)(((float)heros[i]->health/heros[i]->max_health)*100) << "%";
            else if((int)(((float)heros[i]->health/heros[i]->max_health)*100) < 100)
                thestring << " " << (int)(((float)heros[i]->health/heros[i]->max_health)*100) << "%";
            else
                thestring << (int)(((float)heros[i]->health/heros[i]->max_health)*100) << "%";
        }
        text.push_back(thestring.str());
    }
    
    myblock = new class Textbox(text, "Hero");

    return myblock;
}






















