#include<mpi.h>
#include<iostream>
using namespace std;


int main(int argc, char* argv[]) {
    MPI_Init(&argc, &argv);

    int worldSize;
    MPI_Comm_size(MPI_COMM_WORLD, &worldSize);
    
    int worldRank;
    MPI_Comm_rank(MPI_COMM_WORLD, &worldRank);

    if(worldRank == 0) {
        cout<< "worldSize = " <<worldSize << endl;
        cout<< "rank = " << worldRank << endl;
        char processorName[MPI_MAX_PROCESSOR_NAME] ={0};
        int name_len;
        MPI_Get_processor_name(processorName, &name_len);
        cout<<"processor name = " << processorName <<endl;
    } else {
        cout<< "rank = " << worldRank << endl;
    }

    MPI_Finalize();
    return 0;
}