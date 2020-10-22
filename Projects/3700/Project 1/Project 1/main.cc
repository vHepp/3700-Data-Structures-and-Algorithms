#include "point.h"

int main(){
    int32_t k;
    cin >> k; // sets the size
	
    Polygon Q(k);
    
	Point p1;
	cin >> p1; 
	
	Point p2 = Q.FindOutsidePoint(Q, p1);
	
	int32_t count = 0; // checks intersection for all but last segment
	for (int32_t i = 0; i < k-1; i++) {
		Point q1 = Q.getPoint(i);
		Point q2 = Q.getPoint(i+1);
		if (Q.Intersect(p1, p2, q1, q2))
			count++;
	}
	
	Point q1 = Q.getPoint(k-1);
	Point q2 = Q.getPoint(0);
	if (Q.Intersect(p1, p2, q1, q2)) //checks last segment for intersection
		count++;
	
	if (count%2 == 0) //0 or even number of intersections
		cout << "Point is outside the polygon" << endl;
	else //odd number of intersections
		cout << "Point is inside the polygon" << endl;
	
    return 0;
	
}

