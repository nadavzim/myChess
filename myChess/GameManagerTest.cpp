#include"GameManger.h"
void TEST_METHOD(GameManger)
{
    Piece* test1 = new Pawn(1,2,true);
    Piece* test2 = new Pawn(1,2,true);
    string s1 = "1a8h";
    string s2 = "1e5c5";
    string s3 = "b28b";
    string s4 = "12ab";
    string s5 = "!a2b";
    vector<string> v = { s1, s2, s3, s4, s5 }   ;
    //Assert  
    //Assert::AreEqual(name, mc.GetName());
}