#include <iostream>
#include "SIDLL.h"

int main () {
	SIDLL s = SIDLL();
    s.setVerborsity(0);

    printf("Inserting...\n");
    for (int i = 0; i < 1000; i += 1) {
        s.insertNode(i, i);
    }

    printf("Length:%d\n", s.getLength());
    printf("maxKey:%f\n", s.toDouble(s.getMaxKey()));
    printf("minKey:%f\n", s.toDouble(s.getMinKey()));
    printf("Mean:%f\n", s.getMean());
    printf("Median:%f\n\n", s.getMedian());
	
    printf("Deleting...\n");
    for (int i = 0; i < 950; i += 1) {
        s.deleteNode(i);
    }

    printf("Length:%d\n", s.getLength());
    printf("maxKey:%f\n", s.toDouble(s.getMaxKey()));
    printf("minKey:%f\n", s.toDouble(s.getMinKey()));
    printf("Mean:%f\n", s.getMean());
    printf("Median:%f\n", s.getMedian());
	
	return 0
}