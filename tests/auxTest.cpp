#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

int getRandomInt(int min, int max){
	 return min + (rand() % static_cast<int>(max - min + 1));
}

int getShapeSize(std::vector<int> &vec){
	int shapeSize = 1;
	for(int i = 0; i < vec.size(); i++){
		shapeSize *= vec[i];	
	}
	return shapeSize;
}

bool thePositionWasFilled(int index, std::vector<int> &vDimensions, std::vector<int> &vSubscripts){
	if(vSubscripts[index] > vDimensions[index]){
		return true;
	}
	return false;
}

void computeSubscript(int index, std::vector<int> &vDimensions, std::vector<int> &vSubscripts){
	vSubscripts[0] = 0;
	for(int count = 1; count <= index; count++){
		vSubscripts[0]++;
		for(int i = 0; i < vDimensions.size(); i++){
			if(thePositionWasFilled(i, vDimensions, vSubscripts)){
				vSubscripts[i] = 1;
				vSubscripts[i + 1]++;
			}
		}
		std::cout << std::endl << count << ": " ;
		for(int i = 0; i < vSubscripts.size(); i++){
			std::cout << vSubscripts[i] << " ";
		}
	}
}

void ind2sub(int index, std::vector<int> &vDimensions, std::vector<int> &vSubscripts){
	
	for(int i = 0; i < vDimensions.size(); i++){
		vSubscripts.push_back(1);
	}
	computeSubscript(index, vDimensions, vSubscripts);
}

int main(){

	int size = 3;
	std::vector<int> vDimensions{3, 5, 4};
	std::cout << std::endl;
	
	for(int i = 0; i < size; i++){
		std::cout << vDimensions[i] << " ";
	}
	
	std::cout << std::endl;

	std::vector<int> vSubscripts;	
	ind2sub(getShapeSize(vDimensions), vDimensions, vSubscripts);
	std::cout << std::endl;

	return 0;
}
