/** @file element.h
 * Contains declarations of Element
 */
#include <list>
#include <memory>
#include <array>

/**
 * An element that belongs to some node
 *
 * @author Kristoffer Jonsson
 */

class Element {
public:
	virtual double getQ() = 0;
	virtual double getLambda() = 0;
	virtual double getMu() = 0;
private:
};