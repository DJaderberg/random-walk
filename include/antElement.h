/** @file antElement.h
 * Contains declarations of AntElement
 */
#pragma once
#include <list>
#include <memory>
#include <array>
#include "element.h"

/**
 * An AntElement that belongs to some node
 *
 * @author Kristoffer Jonsson
 */


class AntElement : public Element {
	public:
		///Reinforcement intensity
		constexpr static double q = 0.0001;
		///Conductivity decrease rate
		constexpr static double lambda = 0.001;
		///Road maintenance cost factor
		constexpr static double mu  = 1.1;
};
