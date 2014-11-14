#include "random-walk.h"
#include <sstream>
#include <ios>
#include <iomanip>

int main() {
    std::string filename = "data/nodes2d.txt";
    std::string dataPath = "data/save.txt";
    std::shared_ptr<AntElement> e(new AntElement());
    algorithmCreator create = CurrentWalk::create;
    int nCount = 20000;
    int writeDataInterval = 25;
    int writeGraphicsInterval = 1;
    
#ifdef GRAPHICS
    std::string imageSavePath = "img/a";
    generateGraphics(filename, dataPath, imageSavePath, e, create, nCount/writeDataInterval, writeGraphicsInterval);
#else
    double dt = 0.1;
    //generateData(filename, dataPath, e, create, nCount, dt, writeDataInterval);
    generateData(filename, dataPath, e, create, nCount, dt, writeDataInterval, "data/saveLAST.txt");
#endif
    return 0;
}

