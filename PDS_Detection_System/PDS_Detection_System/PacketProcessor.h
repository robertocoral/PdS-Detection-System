#pragma once
#include <stdlib.h>
#include <stdio.h>

#include <mysqlx/xdevapi.h>
#include <dlib-19.16\dlib\optimization.h>
#include <dlib-19.16\dlib\global_optimization.h>

#include "CoverageArea.h"

typedef dlib::matrix<double, 0, 1> column_vector;

class PacketProcessor
{
private:

	int esp_number;
	double rssiAtOneMeter, rssiDiv;

	CoverageArea ca;

	double getDistanceFromRSSI(double rssi);

	double static dist(double x1, double y1, double x2, double y2);

	double static meanSquareError(const column_vector& m);

	void trilaterate(double * pos_x, double * pos_y);

	void readRssiParam();

public:

	PacketProcessor(int count);

	void process();
};

