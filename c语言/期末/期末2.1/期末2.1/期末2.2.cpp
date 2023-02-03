#include <iostream>
using namespace std;
class Triangle
{
public:
	Triangle(float Lenth);
	~Triangle();
	void ChangeLenth(float Source);
	float TriangleArea();
private:
	float Lenth;
};
class Tetrahedron :public Triangle
{
public:
	Tetrahedron(float Lenth, float Height);
	~Tetrahedron();
	void ChangeHeight(float Source);
	float VolumeTetrahedron();
private:
	float Height;
};
Triangle::Triangle(float Lenth)
{
	if (Lenth >= 0)
	{
		this->Lenth = Lenth;
	}
	else
	{
		this->Lenth = 0;
	}
}
Triangle::~Triangle()
{
	;
}
void Triangle::ChangeLenth(float Source)
{
	if (Source >= 0)
	{
		Lenth = Source;
	}
}
float Triangle::TriangleArea()
{
	const float Sqrt3 = 1.732;
	return ((Sqrt3 / 4) * Lenth * Lenth);
}
Tetrahedron::Tetrahedron(float Lenth, float Height):Triangle(Lenth)
{
	if (Height < 0)
	{
		Height = 0;
	}
	else
	{
		this->Height = Height;
	}
}
Tetrahedron::~Tetrahedron()
{
	;
}
void Tetrahedron::ChangeHeight(float Source)
{
	if (Source >= 0)
	{
		Height = Source;
	}
}
float Tetrahedron::VolumeTetrahedron()
{
	float Area = TriangleArea();
	return Area * Height / 3;
}
int main(void)
{
	float Lenth = 0;
	float Height = 0;
	cin >> Lenth >> Height;
	Tetrahedron MyTetrahedron(Lenth, Height);
	float MyVolume = MyTetrahedron.VolumeTetrahedron();
	cout << MyVolume << endl;
	return 0;
}