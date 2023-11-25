class question
{
    public:
        question(int score, string::string cat);        //determine Q
        
        int check(string::string ans);        //return whether the answer is correct

        void printQ(int num) const;
        int getscore() const;

    private:
        string::string Q;
        string::string cat;
        int score;
}