struct Score
{
	string x;
	int y;
	Score() :x(""), y(0) { }
	Score(string xx, int yy) :x(xx), y(yy) { }
};

ostream& operator<<(ostream& os, const Score& p)
{
    return os << p.x << "  " << p.y << "\n";
}
istream& operator>>(istream& is, Score& p)
{
    string x;
    int y;
    is >> x >> y;
    if (!is) return is; 
}
bool operator ==(const Score& p1, const Score& p2)
{
	return p1.x==p2.x && p1.y==p2.y;
}
bool operator<(const Score& s1, const Score& s2)
{
	return s1.y < s2.y;
}