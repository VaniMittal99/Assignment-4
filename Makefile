target:
	g++ -Wall -g -o final_debug MainFile.cpp PrintFile.cpp 
	g++ -Wall -O2 -o final_optimized MainFile.cpp PrintFile.cpp 

clean:
	rm -f *.o final_debug final_optimized final