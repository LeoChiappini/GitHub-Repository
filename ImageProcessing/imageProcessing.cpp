#include <vector>
#include <fstream>
#include <iostream>
using namespace std; 

struct Pixel { // Done
    unsigned char red;
	unsigned char green;
	unsigned char blue;

	Pixel() {
		red = 0;
		green = 0;
		blue = 0;
	}

	Pixel(unsigned char R, unsigned char G, unsigned char B) {
		red = R;
		green = G;
		blue = B;
	}

    bool operator==(const Pixel &pix) const { // Done
        if (!(this->red == pix.red)) {
            return false;
        }
        else if (!(this->green == pix.green)) {
            return false;
        }
        else if (!(this->blue == pix.blue)) {
            return false;
        }
        else {
            return true;
        }
    }
};

struct Header { // Done
	char idLength;
	char colorMapType;
	char dataTypeCode;
	short colorMapOrigin;
	short colorMapLength;
	char colorMapDepth;
	short xOrigin;
	short yOrigin;
	short width;
	short height;
	char bitsPerPixel;
	char imageDescriptor;
};

//pass an empty Header obj and an empty vector of Pixels and this returns a vector filled of pixels, and a Header that stores all the correct read in values for Header. 
void readData(const string& path, vector<Pixel>& vec, Header& header) { // Done

	ifstream inFS(path, ios_base::binary); // Creates file reader

	inFS.read((char*)&header.idLength, sizeof(header.idLength));
	inFS.read((char*)&header.colorMapType, sizeof(header.colorMapType));
	inFS.read((char*)&header.dataTypeCode, sizeof(header.dataTypeCode));
	inFS.read((char*)&header.colorMapOrigin, sizeof(header.colorMapOrigin));
	inFS.read((char*)&header.colorMapLength, sizeof(header.colorMapLength));
	inFS.read((char*)&header.colorMapDepth, sizeof(header.colorMapDepth));
	inFS.read((char*)&header.xOrigin, sizeof(header.xOrigin));
	inFS.read((char*)&header.yOrigin, sizeof(header.yOrigin));
	inFS.read((char*)&header.width, sizeof(header.width));
	inFS.read((char*)&header.height, sizeof(header.height));
	inFS.read((char*)&header.bitsPerPixel, sizeof(header.bitsPerPixel));
	inFS.read((char*)&header.imageDescriptor, sizeof(header.imageDescriptor));

    cout <<"Width: " << header.width << " Height: " << header.height << endl;

	// Reads pixel information

	int pixelNum = header.width * header.height;

    unsigned char R;
    unsigned char G;
    unsigned char B;

	for (int i = 0; i < pixelNum; i += 1) {

        inFS.read((char*)&B, 1); // Can use sizeof(pix->blue) but testing since size should be 1 byte
        inFS.read((char*)&G, 1);
		inFS.read((char*)&R, 1);

        Pixel* pix = new Pixel(R, G, B); // Creates pixel with proper RGB data and pushes it into the vector

        vec.push_back(*pix);
	}

    inFS.close();
}

//pass this function a Header Object and a List of all the pixels
void writeData(Header& header, vector<Pixel> vec, string path) { // Done

    ofstream outFS(path, ios_base::out | ios_base::binary);

    // Writing header elements
    outFS.write((char*)&header.idLength, sizeof(header.idLength));
	outFS.write((char*)&header.colorMapType, sizeof(header.colorMapType));
	outFS.write((char*)&header.dataTypeCode, sizeof(header.dataTypeCode));
	outFS.write((char*)&header.colorMapOrigin, sizeof(header.colorMapOrigin));
	outFS.write((char*)&header.colorMapLength, sizeof(header.colorMapLength));
	outFS.write((char*)&header.colorMapDepth, sizeof(header.colorMapDepth));
	outFS.write((char*)&header.xOrigin, sizeof(header.xOrigin));
	outFS.write((char*)&header.yOrigin, sizeof(header.yOrigin));
	outFS.write((char*)&header.width, sizeof(header.width));
	outFS.write((char*)&header.height, sizeof(header.height));
	outFS.write((char*)&header.bitsPerPixel, sizeof(header.bitsPerPixel));
	outFS.write((char*)&header.imageDescriptor, sizeof(header.imageDescriptor));
    

    int pixelNum = header.width * header.height;

    for(int i = 0; i < pixelNum; i += 1) {

        outFS.write((char*)&vec[i].blue, sizeof(vec[i].blue));
        outFS.write((char*)&vec[i].green, sizeof(vec[i].green));
        outFS.write((char*)&vec[i].red, sizeof(vec[i].red));
    } 
}

//Function that takes in two pictures and checks whether or not they are equal
void Test(string fileOne, string fileTwo) // Done
{
    int mistakeNumber = 0;

    Header headerOne;
    Header headerTwo;

    vector<Pixel> vecOne;
    vector<Pixel> vecTwo;

    readData(fileOne, vecOne, headerOne);
    readData(fileTwo, vecTwo, headerTwo);

    // Printing dimensions and # of pixels
    cout << "Dimensions for first file: " << headerOne.width << " x " << headerOne.height << ". # of pixels: " << vecOne.size() << endl;
    cout << "Dimensions for second file: " << headerTwo.width << " x " << headerTwo.height << ". # of pixels: " << vecTwo.size() << endl;

    // Comparing dimensions
    if (!(headerOne.width == headerTwo.width)) {
        cout << "Widths do not match" << endl;
        mistakeNumber += 1;
    }

    if (!(headerOne.height == headerTwo.height)) {
        cout << "Heights do not match" << endl;
        mistakeNumber += 1;
    }

    if (!(vecOne == vecTwo)) {
        cout << "# of pixels does not match" << endl;
        mistakeNumber += 1;
    }

    // Comparing pixels - Assumes both vectors have the same size
    for(int i = 0; i < vecOne.size(); i += 1) {
        if(!(vecOne[i] == vecTwo[i])) {
            //cout << "Pixel number " << i << " does not match" << endl;
            mistakeNumber++;
        }
    }

    if (mistakeNumber == 0) {
        cout << "Images are equal" << endl;
    }
    else {
        cout << "Images are NOT equal" << endl;
    }
    cout << endl;
}

void AddToRed(vector<Pixel>& pix, int num) { // Done
	for (unsigned int i = 0; i < pix.size(); i += 1) {
        // Calculates new red value
		int newR = (int)pix[i].red + num;
		if (newR > 255) {newR = 255; }
		
		//update the value of red in each pixel;
		pix[i].red = (unsigned char)newR;
	}
}

void AddToGreen(vector<Pixel>& pix, int num) { // Done
	for (unsigned int i = 0; i < pix.size(); i += 1) {
        // Calculates new green value
		int newG = (int)pix[i].green + num;
		if (newG > 255) {newG = 255; }
		
		//update the value of green in each pixel;
		pix[i].green = (unsigned char)newG;
	}
}

void AddToBlue(vector<Pixel>& pix, int num) { // Done
	for (unsigned int i = 0; i < pix.size(); i += 1) {
        // Calculates new blue value
		int newB = (int)pix[i].blue + num;
		if (newB > 255) {newB = 255; }
		
		//update the value of blue in each pixel;
		pix[i].blue = (unsigned char)newB;
	}
}

void Multiply(vector<Pixel>& pixA, vector<Pixel>& pixB, vector<Pixel>& pixRes) { // Done

    for (unsigned int i = 0; i < pixA.size(); i += 1) {
        // Calculating new values for RGB
        float newR = (((float)pixA[i].red * (float)pixB[i].red) / 255.0f) + 0.5f;
        float newG = (((float)pixA[i].green * (float)pixB[i].green) / 255.0f) + 0.5f;
        float newB = (((float)pixA[i].blue * (float)pixB[i].blue) / 255.0f) + 0.5f;

        // Creating a pixel with the calculated values
        Pixel* pix = new Pixel((unsigned char)newR, (unsigned char)newG, (unsigned char)newB);

        pixRes.push_back(*pix);
    }
}

void Subtract(vector<Pixel>& pixA, vector<Pixel>& pixB, vector<Pixel>& pixRes) { // Done

    for (unsigned int i = 0; i < pixA.size(); i += 1) {
        // Calculating new values for RGB
        float newR = (float)pixA[i].red - (float)pixB[i].red;
        float newG = (float)pixA[i].green - (float)pixB[i].green;
        float newB = (float)pixA[i].blue - (float)pixB[i].blue;

        // If values are negative, change to 0
        if (newR < 0) {newR = 0; }
        if (newG < 0) {newG = 0; }
        if (newB < 0) {newB = 0; }

        Pixel* pix = new Pixel((unsigned char)newR, (unsigned char)newG, (unsigned char)newB);
        pixRes.push_back(*pix);
    }
}

void Screen(vector<Pixel>& pixA, vector<Pixel>& pixB, vector<Pixel>& pixRes) {  // Done 

    Pixel* pix; // Holding pointer for new pixels
    for (unsigned int i = 0; i < pixA.size(); i += 1) {
        // Calculating the new values for RGB
        float newR = (1.0f - ((1.0f - ((float)pixA[i].red)/ 255.0f) * (1.0f - ((float)pixB[i].red)/ 255.0f))) * 255.0f + 0.5f;
        float newG = (1.0f - ((1.0f - ((float)pixA[i].green)/ 255.0f) * (1.0f - ((float)pixB[i].green)/ 255.0f))) * 255.0f + 0.5f;
        float newB = (1.0f - ((1.0f - ((float)pixA[i].blue)/ 255.0f) * (1.0f - ((float)pixB[i].blue)/ 255.0f))) * 255.0f + 0.5f;

        pix = new Pixel((unsigned char)newR, (unsigned char)newG, (unsigned char)newB);

        pixRes.push_back(*pix);
    }
}

// Must finish
void Overlay(vector<Pixel>& pixA, vector <Pixel>& pixB, vector<Pixel>& res) { // Done
    
	for (unsigned int i = 0; i < pixA.size(); i += 1) {

        // Red vars
        float redValA = pixA[i].red / 255.0f;
		float redValB = pixB[i].red / 255.0f;
        float newR = 0;

        // Green vars
        float greenValA = pixA[i].green / 255.0f;
        float greenValB = pixB[i].green / 255.0f;
        float newG = 0;

        // Blue vars
        float blueValA = pixA[i].blue / 255.0f;
        float blueValB = pixB[i].blue / 255.0f;
        float newB = 0;
		
		// Red Manipulation
		if (redValB <= 0.5f) {
			newR = (2.0f * redValA * redValB) * 255.0f + 0.5f;
		}
		else {
			newR = (1.0f - (2.0f * (1.0f - redValA) * (1.0f - redValB))) * 255.0f + 0.5f;
		}

        // Green Manipulation
		if (greenValA <= 0.5f) {
			newG = (2.0f * greenValA * greenValB) * 255.0f + 0.5f;
		}
		else {
			newG = (1.0f - (2.0f * (1.0f - greenValA) * (1.0f - greenValB))) * 255.0f + 0.5f;
		}

		// Blue Manipulation
		if (blueValB <= 0.5f) {
			newB = (2.0f * blueValA * blueValB) * 255.0f + 0.5f;
		}
		else {
			newB = (1.0f - (2.0f * (1.0f - blueValA) * (1.0f - blueValB)))* 255.0f + 0.5f;
        }
		
        // Pixel Creation and pushing
        Pixel* pixel;

        pixel = new Pixel((unsigned char)newR, (unsigned char)newG, (unsigned char)newB);
		res.push_back(*pixel);
	}
}

void Flip(vector<Pixel>& pix, vector<Pixel>& res) { // Done
    unsigned char newR;
    unsigned char newG;
    unsigned char newB;
    Pixel* pixel;
	for (unsigned int i = 0; i < pix.size(); i++) {
        // Calculates new RGB values
        newR = pix[(unsigned int)pix.size() - i - 1].red;
        newG = pix[(unsigned int)pix.size() - i - 1].green;
        newB = pix[(unsigned int)pix.size() - i - 1].blue;

        pixel = new Pixel(newR, newG, newB);
        res.push_back(*pixel);
	}
}

void Task1() { // Done

	//Create needed headers and vectors
	Header headerOne; 
    Header headerTwo;

	vector<Pixel> pixA;
    vector<Pixel> pixB;
    vector<Pixel> res;

    // Read files to the corresponding vectors and headers
	readData("input/layer1.tga", pixA, headerOne);
	readData("input/pattern1.tga", pixB, headerTwo);

    // Multiply both layers together
	Multiply(pixA, pixB, res);

	// Write resultant image to set path
	writeData(headerOne, res, "output/part1.tga");
}

void Task2() { // Done

    //Create needed headers and vectors
    Header headerOne;
    Header headerTwo;

    vector<Pixel> pixA;
    vector<Pixel> pixB;
    vector<Pixel> res;

    // Read files to the corresponding vectors and headers
    readData("input/layer2.tga", pixA, headerOne);
    readData("input/car.tga", pixB, headerTwo);

    // Subtract both layers
    Subtract(pixB, pixA, res);

    // Write resultant image to set path
    writeData(headerOne, res, "output/part2.tga");
}

void Task3() { // Done

    //Create needed headers and vectors
    Header headerOne;
    Header headerTwo;
    Header headerThree;

    vector<Pixel> pixA;
    vector<Pixel> pixB;
    vector<Pixel> pixC;
    vector<Pixel> hold;
    vector<Pixel> res;

    // Read files to the corresponding vectors and headers
    readData("input/layer1.tga", pixA, headerOne);
    readData("input/pattern2.tga", pixB, headerTwo);
    readData("input/text.tga", pixC, headerThree);

    // Multiply both layers together, then screen the 3rd layer
	Multiply(pixA, pixB, hold);
    Screen(hold, pixC, res);

    // Write resultant image to set path
    writeData(headerOne, res, "output/part3.tga");
}

void Task4() { // Done

    //Create needed headers and vectors
    Header headerOne;
    Header headerTwo;
    Header headerThree;

    vector<Pixel> pixA;
    vector<Pixel> pixB;
    vector<Pixel> pixC;
    vector<Pixel> hold;
    vector<Pixel> res;

    // Read files to the corresponding vectors and headers
    readData("input/layer2.tga", pixA, headerOne);
    readData("input/circles.tga", pixB, headerTwo);
    readData("input/pattern2.tga", pixC, headerThree);

    // Multiply both layers together, then subtract the 3rd layer
    Multiply(pixA, pixB, hold);
    Subtract(hold, pixC, res);

    // Write resultant image to set path
    writeData(headerOne, res, "output/part4.tga");
}

void Task5() { // Done

    //Create needed headers and vectors
    Header headerOne;
    Header headerTwo;

    vector<Pixel> pixA;
    vector<Pixel> pixB;
    vector<Pixel> res;

    // Read files to the corresponding vectors and headers
    readData("input/layer1.tga", pixA, headerOne);
    readData("input/pattern1.tga", pixB, headerTwo);

    // Overlay both layers together
    Overlay(pixA, pixB, res);

    // Write resultant image to set path
    writeData(headerOne, res, "output/part5.tga");
}

void Task6() { // Done

    //Create needed headers and vectors 
	Header header;
	vector<Pixel> pix;

    // Read files to the corresponding vectors and headers
	readData("input/car.tga", pix, header);
	
    // Add green to layer
	AddToGreen(pix, 200);

    // Write resultant image to set path
	writeData(header, pix, "output/part6.tga");
}

void Task7() { // Done

    //Create needed headers, vectors, and holding variables
	Header header; 
	vector<Pixel> pix;

    int newR;

    // Read files to the corresponding vectors and headers
	readData("input/car.tga", pix, header);

    // Loops through vector to set new red and blue values
	for (unsigned int i = 0; i < pix.size(); i++) {

        // Multiplies red value by 4
		newR = (int)pix[i].red * 4;
		if (newR > 255) { newR = 255; }

		// Sets new red and blue values
		pix[i].red = newR;
		pix[i].blue = 0;
	}

    // Write resultant image to set path
	writeData(header, pix, "output/part7.tga");
}

void Task8B() { // Done

    //Create needed headers, vectors, and holding variables 
	Header header; 
	vector<Pixel> pix; 
    vector <Pixel> Blue;
    Pixel* pixel;

    // Read files to the corresponding vectors and headers
	readData("input/car.tga", pix, header);
	
	// Loops through vector and sets pixel properties
	for (unsigned int i = 0; i < pix.size(); i++) {
		pixel = new Pixel(pix[i].blue, pix[i].blue, pix[i].blue);
		Blue.push_back(*pixel);
    }
	
    // Write resultant image to set path
	writeData(header, Blue, "output/part8_b.tga");
}

void Task8G() { // Done

    //Create needed headers, vectors, and holding variables 
	Header header; 
	vector<Pixel> pix; 
    vector <Pixel> Green;
    Pixel* pixel;

    // Read files to the corresponding vectors and headers
	readData("input/car.tga", pix, header);

    // Loops through vector and sets pixel properties
    for (unsigned int i = 0; i < pix.size(); i++) {
        pixel = new Pixel(pix[i].green, pix[i].green, pix[i].green);
		Green.push_back(*pixel);
    }

    // Write resultant image to set path
    writeData(header, Green, "output/part8_g.tga");
}

void Task8R() { // Done

	//Create needed headers, vectors, and holding variables 
	Header header; 
	vector<Pixel> pix; 
    vector <Pixel> Red;
    Pixel* pixel;

    // Read files to the corresponding vectors and headers
	readData("input/car.tga", pix, header);

    // Loops through vector and sets pixel properties
    for (unsigned int i = 0; i < pix.size(); i++) {
        pixel = new Pixel(pix[i].red, pix[i].red, pix[i].red);
		Red.push_back(*pixel);
    }

    // Write resultant image to set path
    writeData(header, Red, "output/part8_r.tga");
}

void Task9() { // Done

    //Create needed headers and vectors
    Header headerRed;
    Header headerGreen;
	Header headerBlue; 

    vector <Pixel> pixRed;
    vector <Pixel> pixGreen;
	vector <Pixel> pixBlue;
    vector<Pixel> res;

    Pixel* pixel;

    // Read files to the corresponding vectors and headers
	readData("input/layer_red.tga", pixRed, headerRed);
	readData("input/layer_green.tga", pixGreen, headerGreen);
    readData("input/layer_blue.tga", pixBlue, headerBlue);

    // Loops through and populates res vector
	for (unsigned int i = 0; i < pixRed.size(); i++) {
        pixel = new Pixel(pixRed[i].red, pixGreen[i].green, pixBlue[i].blue);
		res.push_back(*pixel);
	}

    // Write resultant image to set path
	writeData(headerRed, res, "output/part9.tga");
}

void Task10() { // Done

    //Create needed headers and vectors
    Header header;
    vector<Pixel> pix;
    vector<Pixel> flipped;

    // Read files to the corresponding vectors and headers
    readData("input/text2.tga", pix, header);

    // Flips the pixels
    Flip(pix, flipped);

    // Write resultant image to set path
    writeData(header, flipped, "output/part10.tga");
}

int main() {
	Task1();
	cout << "Testing Task 1" << endl;
	Test("output/part1.tga", "examples/EXAMPLE_part1.tga");
    

	Task2();
	cout << "Testing Task 2" << endl;
	Test("output/part2.tga", "examples/EXAMPLE_part2.tga");
    

	Task3();
	cout << "Testing Task 3" << endl;
	Test("output/part3.tga", "examples/EXAMPLE_part3.tga");
    
	
	Task4();
	cout << "Testing Task 4" << endl;
	Test("output/part4.tga", "examples/EXAMPLE_part4.tga");

	Task5();
	cout << "Testing Task 5" << endl;
	Test("output/part5.tga", "examples/EXAMPLE_part5.tga");

	Task6();
	cout << "Testing Task 6" << endl;
	Test("output/part6.tga", "examples/EXAMPLE_part6.tga");

	Task7();
	cout << "Testing Task 7" << endl;
	Test("output/part7.tga", "examples/EXAMPLE_part7.tga");

	Task8B();
	cout << "Testing Task 8B" << endl;
	Test("output/part8_b.tga", "examples/EXAMPLE_part8_b.tga");

	Task8G();
	cout << "Testing Task 8G" << endl;
	Test("output/part8_g.tga", "examples/EXAMPLE_part8_g.tga");

	Task8R();
	cout << "Testing Task 8R" << endl;
	Test("output/part8_r.tga", "examples/EXAMPLE_part8_r.tga");

	Task9();
	cout << "Testing Task 9" << endl;
	Test("output/part9.tga", "examples/EXAMPLE_part9.tga");

	Task10();
	cout << "Testing Task 10" << endl;
	Test("output/part10.tga", "examples/EXAMPLE_part10.tga");
    
}
