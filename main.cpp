#include <iostream>
#include <vector>

class GrayCodeGenerator {
    public:
    std::vector < int > RecursiveSolution (int n) {
        if(n == 0)
            return { 0 };
        if( n == 1)
            return { 0, 1 };
        auto a = RecursiveSolution ( n - 1 );
        auto highestBit = (1 << (n - 1) );
        std::vector<int> result;
        int mask =  0 ;
        for ( int i=0; i < a.size() ; i++ ) {
            result.push_back( (  mask & highestBit) | a[i] );
            mask = ~mask;
            result.push_back( (  mask & highestBit) | a[i] );
        }
        
        return result;
    }
};

int main( int argc, char* argv[] ) {
    using namespace std;

    GrayCodeGenerator p;
    auto g = p.RecursiveSolution ( 4 );
    for(int i = 0; i < g.size(); i++) {
        cout << std::dec << g[i] << "\t => \t" << std::bitset<8>(g[i]) << endl;
    }
    return 0;
}
