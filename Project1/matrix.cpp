// Justin Ventura COSC320
// Project 1: matrix.h

Matrix* operator+(Matrix *a, Matrix *b)
{
	if (a->r != b->r || a->c != b->c) 
	{
		std::cout << "ERROR.\n";
		return nullptr;
	}
	Matrix *c(a->r, a->c);
	for (auto i = 0)
}
Matrix* operator-(Matrix *a, Matrix *b)
{

}
Matrix* operator*(Matrix *a, Matrix *b)
{

}