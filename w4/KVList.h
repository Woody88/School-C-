// Workshop 4
// Woodson Delhia
// BTP305 

#include<iostream>

template <class K, class V, int N>
class KVList {
    K product[N];
    V price[N];
   	size_t counter; // Counter that tracks the index of last added item
   	
	public:
	// Default Contructor
    KVList(){
     	product[0] = "\0";
     	price[0] = 0.0;
     	counter = 0;
     }

     // Return array size
     size_t size() const{ return counter; }
     
     // Returns key value at position i 
     const K& key(int i) const { return product[i]; }

     // Returns value at position i 
     const V& value(int i) const { return price[i]; }

     // Insert accepted argument innt product and price array and return updated current object
     KVList& add(const K& str, const V& pce){
     	if(counter == 0){
     		product[counter] = str;
     		price[counter] = pce;
     		counter++;
     		return *this;
     	}
     	else if( counter == N) { }
     	else{
     		product[counter] = str;
     		price[counter] = pce;
     		counter++;
     		return *this;
     	}
    }

    // Find value of key using accepted key argument and returns index
    int find(const K& k) const{
    	for(int i = 0; i < counter; i++){
    		if (product[counter] == k){
    			return (int)counter;
    		}
    	}
    }

    // Replace value of produce and price argument with new values at position i and return updated current object
    KVList& replace(int i, const K& k, const V& v){
		product[i]  = k;
		price[i] = v;

		return *this;
    }

 };
