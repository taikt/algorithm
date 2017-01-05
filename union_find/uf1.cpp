// 22.12.2016, Tai<taitrananhvn@gmail.com>

// Union-Find Disjoint Set data structure
// https://visualgo.net/ufds

// Tai (taitrananhvn@gmail.com, 20.12.2016)

#include <cstdio>
#include <vector>
using namespace std;

class UnionFind {
private:
	int numSets; // number of disjoint sets
	// p: parent of tree node
	// setSize: size of a disjoint set
	// rank: rank of tree node ~ height of node initially
	vector<int> rank, p, setSize; 

public:
	UnionFind(int V) {
		numSets = V; // V disjoint sets initially
		rank.assign(V,0); 
		p.assign(V,0);
		setSize.assign(V,1);
		for (int i=0; i<V; i++) p[i] = i;
	}

	bool isSameSet(int i, int j) {
		return (findSet(i) == findSet(j));
	}

	int findSet(int i) {
		return ((p[i] == i) ? i : (p[i] = findSet(p[i]))); // path-compression also
	}

	void unionSet(int i, int j) {
		if (!isSameSet(i,j)) {
			numSets--;
			int x = findSet(i); 
			int y = findSet(j);
			if (rank[x] > rank[y]) {
				p[y] = x;
				setSize[x] += setSize[y];
			} else {
				p[x] = y;
				setSize[y] += setSize[x];
				if (rank[x] == rank[y]) rank[y]++;	
			}
		}
	}

	int sizeofSet(int i) {
		return setSize[findSet(i)];
	}

	int numDisjointSets() {
		return numSets;
	}
};

int main() {
	UnionFind UF(3);
	printf("number of Disjoint sets %d\n",UF.numDisjointSets());
	for (int i=0; i< 3; i++) {
		printf("size of disjoint set %d=%d\n", i,UF.sizeofSet(i));
		printf("representative item(tree root) of disjoint set %d is %d\n",i,UF.findSet(i));
	}

	UF.unionSet(0,2);

	printf("\nafter join two set\n");
	for (int i=0; i< 3; i++) {
		printf("size of disjoint set %d=%d\n", i,UF.sizeofSet(i));
		printf("representative item(tree root) of disjoint set %d is %d\n",i,UF.findSet(i));
	}

	printf("number of Disjoint sets %d\n",UF.numDisjointSets());
}
