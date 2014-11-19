/** @file generateGraphics.cpp
 * Function for generating images from data
 */
//
//  Created by Kristoffer Jonsson on 13/11/14.
//

#ifdef GRAPHICS
#include "generateGraphics.h"
#include <string>
#include <fstream>

/**
 * Function for generating images from data
 */
void generateGraphics(std::string nodePath, std::string dataReadPath, std::string imageSavePath, std::shared_ptr<Element> e, algorithmCreator create, int nCount, int writeInterval, bool force) {
    
    NodeSetGraphics graphics = NodeSetGraphics();
    graphics.init();
    
    PositionedNodeSet set = PositionedNodeSet(nodePath, create, e);
    graphics.XYMinMax(set);
    
    
    std::ifstream ifsMinMx(dataReadPath);
    
    for (int i = 0; i < nCount; i++) {
        set.readData(ifsMinMx);
        graphics.NAndFlowMinMax(set);
    }
    
    ifsMinMx.close();
    
    std::cout << graphics.toString();
    
    std::ifstream ifs(dataReadPath);
    
    int j = 0;
	if (!force) {
		while (true) {
			std::stringstream imgFilename(imageSavePath, std::ios_base::in|std::ios_base::out);
			imgFilename << imageSavePath;
			imgFilename << std::setfill('0') << std::setw(6) << j << ".png";
			std::string imgFilenameStr = imgFilename.str();
			if (!exists(imgFilenameStr)) {
				break;
			} else {
				j++;
			}
		}
	}

	if (j != 0) {
		std::cout << "Found existing images, creating new images starting at number " << j << "\n";
	}
    for (int i = 0; i < nCount; i++) {
        set.readData(ifs);
        //std::cout << set.toString();
        if (i % writeInterval == 0) {
            set.reinitialize();
            std::stringstream imgFilename(imageSavePath, std::ios_base::in|std::ios_base::out);
            imgFilename << imageSavePath;
            imgFilename << std::setfill('0') << std::setw(6) << j++ << ".png";
            std::string imgFilenameStr = imgFilename.str();
            graphics.drawEdges(set, 0);
            graphics.drawNodes(set, 0);
            graphics.writeToFile(imgFilenameStr);
            graphics.repaint();
        }
    }
    
    ifs.close();
    
    
}
#endif
