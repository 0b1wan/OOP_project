#include "grid.hpp"


Grid::Grid(int row, int col)
{
    columns = col;
    rows = row;

    square=new Block**[rows];
    for (int c=0; c<columns; c++)
    {
        square[c]=new Block*[columns];
    }

    for (int r=0; r<rows; r++)
    {
        for (int c=0; c<columns; c++)
        {

            square[r][c] = new class Block(r, c, "Common");
        }
    }
    theMap = new class Map();
    createVisualMap();
}

int Grid::createVisualMap()
{

    // Create visual map...

    // First Line
    Textbox* Title = new Textbox({"\n Displaying [ MAP ] ... "}, "Title");
    theMap->add_textbox(Title, -1, true);

    theMap->add_textbox(theMap->Space, -1, true);
    theMap->add_textbox(theMap->HorizontalBlock1);
    for (int i=0; i<columns-2; i++)
        theMap->add_textbox(theMap->HorizontalBlock2);
    theMap->add_textbox(theMap->HorizontalBlock3);

    // In-Between Rows...
    for (int r=0; r<rows; r++) {
        // First Textbox
        theMap->add_textbox(theMap->TripleSpace, -1, true);
        theMap->add_textbox(theMap->VerticalBlock);
        if (square[r][0]->block_type == "Common") {
            if(!square[r][0]->hasHeros())
                theMap->add_textbox(theMap->EmptyBlock);
            else
                theMap->add_textbox(theMap->HerosBlock(square[r][0]->heros));
        }
        else if (square[r][0]->block_type == "Market") {
            if (!square[r][0]->hasHeros())
                theMap->add_textbox(theMap->MarketBlock);
            else {
                theMap->MarketBlockWTHeros->text[0].replace(0,0, to_string((int)square[r][0]->heros.size()));
                theMap->add_textbox(theMap->MarketBlockWTHeros);
            }

        }
        else
            theMap->add_textbox(theMap->NonAccessibleBlock);

        // All other Textboxes
        for (int c=1; c<columns; c++) {
            theMap->add_textbox(theMap->VerticalBlock);
            if (square[r][c]->block_type == "Common") {
                if(!square[r][c]->hasHeros())
                    theMap->add_textbox(theMap->EmptyBlock);
                else
                    theMap->add_textbox(theMap->HerosBlock(square[r][c]->heros));
            }
            else if (square[r][c]->block_type == "Market"){
                if (!square[r][c]->hasHeros())
                    theMap->add_textbox(theMap->MarketBlock);
                else {
                    theMap->MarketBlockWTHeros->text[0].replace(0,1, to_string((int)square[r][c]->heros.size()));
                    theMap->add_textbox(theMap->MarketBlockWTHeros);
                }
            }
            else
                theMap->add_textbox(theMap->NonAccessibleBlock);
        }
        theMap->add_textbox(theMap->VerticalBlock);

        // Middle Line
        if (r == rows-1)
            break;
        theMap->add_textbox(theMap->Space, -1, true);
        theMap->add_textbox(theMap->HorizontalBlock4);
        for (int i=0; i<columns-2; i++)
            theMap->add_textbox(theMap->HorizontalBlock1);
        theMap->add_textbox(theMap->HorizontalBlock5);
    }



    // Last Line
    theMap->add_textbox(theMap->Space, -1, true);
    theMap->add_textbox(theMap->HorizontalBlock1);
    for (int i=0; i<columns-2; i++)
        theMap->add_textbox(theMap->HorizontalBlock2);
    theMap->add_textbox(theMap->HorizontalBlock3);
    theMap->add_textbox(theMap->Newline);

    return 0;
}

int Grid::updateVisualMap()
{
    for (int r=0; r<rows; r++)
    {
        for (int c=0; c<columns; c++)
        {
            if (square[c][r]->block_type == "Common") {
                if( !square[c][r]->hasHeros()) {

                    theMap->textbox[r][c] = theMap->EmptyBlock;
                }
                    else
                    theMap->textbox[r][c] = theMap->HerosBlock(square[c][r]->heros);
            }
            else if (square[c][r]->block_type == "Market")
                theMap->textbox[r][c] = theMap->MarketBlock;
            else
                theMap->textbox[r][c] = theMap->NonAccessibleBlock;
        }
    }

    //theMap->textbox[1][3] = theMap->MarketBlock;
    return 0;
}

Grid::~Grid()
{

    //deallocate the array (square) in heap
    for (int i=0; i<columns; i++)
    {
        for (int j=0; j<rows; j++)
        {
            delete square[i][j]; //delete the textbox
        }
    }

    for (int i=0; i<rows; i++)
    {
        delete[] square[i]; //delete all the rows
    }

    delete[] square;

    //deallocate theMap
    delete theMap;

}
int Grid::add_Market(int x, int y)
{
    delete square[x][y];
    square[x][y] = new class Block(x,y,"Market");
    return 0;
}

int Grid::add_NonAccessible(int x, int y)
{
    delete square[x][y];
    square[x][y] = new class Block(x,y,"NonAccessible");
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
    for (int r=0; r<textbox.size(); r++) {
        // find maximum text lines in r row
        int max_lines=0;
        for (int i=0; i<textbox[r].size(); i++) {
            if (max_lines < textbox[r][i]->lines)
                max_lines = textbox[r][i]->lines;
        }

        // print each line
        for (int l=0; l<max_lines; l++) {
            // print l line of each textbox in r row
            for (int j=0; j<textbox[r].size(); j++) {
                if (textbox[r][j]->lines < l+1)
                    for (int s=0; s<textbox[r][j]->text[l-1].size(); s++)
                        cout << " ";
                else {
                    cout << textbox[r][j]->text[l];
                    if ((l>0) && textbox[r][j]->text[l].size() < textbox[r][j]->text[l-1].size()) {
                        int difference = (int)textbox[r][j]->text[l-1].size() - (int)textbox[r][j]->text[l].size();
                        for (int d=0; d<difference; d++)
                            cout << " ";
                    }
                }
            }
            cout << endl;
        }
    }

}


void Map::add_textbox(class Textbox* txt, int charLimit, bool newline)
{

    Textbox * copy = new Textbox(txt->text, txt->box_type);

    if (charLimit == -1)
        charLimit = (int)copy->text[0].size();

    for (int i=0; i<copy->lines; i++) {
        if (copy->text[i].size() > charLimit)
            copy->text[i].erase(charLimit, copy->text[i].size());
    }


    if (newline) {
        vector<Textbox*> myvector;
        myvector.push_back(copy);
        textbox.push_back(myvector);
        r_elements++;
    }
    else {
        textbox[textbox.size()-1].push_back(copy);
        c_elements++;
    }
}

int Map::lineLength(int lineNumber)
{

    if ( (lineNumber > textbox.size()) || (lineNumber < 0) )
        return -1;

    int length = 0;
    for (int i=0; i<textbox[lineNumber].size(); i++) {
        length += textbox[lineNumber][i]->text[0].length();
    }

    return length;
}

Textbox::Textbox(vector<string> txt, string type)
{
    box_type = type;

    lines = (int)txt.size();
    for (int i=0; i<lines; i++)
        text.push_back(txt[i]);
}

Map::~Map(){
  //Deallocate the inner Textbox* (pointers) of the textbox vector
  for (int i=0;i<textbox.size();i++)
  {
    for (int j=0;j<textbox[i].size();j++)
    {
      delete textbox[i][j];
    }
  }
  delete HorizontalBlock1;
  delete HorizontalBlock2;
  delete HorizontalBlock3;
  delete HorizontalBlock4;
  delete HorizontalBlock5;
  delete VerticalBlock;
  delete EmptyBlock;
  delete MarketBlock;
  delete NonAccessibleBlock;
  delete Space;
  delete TripleSpace;
  delete Newline;
  delete MarketBlockWTHeros;


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
