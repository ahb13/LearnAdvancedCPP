#include<mpi.h>
#include<iostream>
using namespace std;

// 多进程将多个数求和，画蛇添足，仅仅为了学习mpi的使用
int main(int argc, char* argv[]) {
    MPI_Init(&argc, &argv);

    int* arr = new int[10000];
    for(int idx=1;idx<10001;idx++) {
        arr[idx -1] = idx;
    }

    int worldSize;
    MPI_Comm_size(MPI_COMM_WORLD, &worldSize);

    int patchSize = 10000 / worldSize;

    int rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    if(rank == 0) { //第一个，主进程
    int start = 0;
    int end = patchSize;
    long sum = 0;
    for(int i0 = start; i0 < end; i0++) {
        sum += (long)arr[i0];
    }

    MPI_Status status;
    for(int j0=1;j0<worldSize;j0++) {
        long sum1 = 0;
        MPI_Recv(&sum1, 1, MPI_LONG, j0, 0, MPI_COMM_WORLD, &status);
        sum += sum1;
    }

    cout<<"master, sum = " << sum << endl;;
    } else if (rank == worldSize - 1) { //最后一个进程
    int start = rank * patchSize;
    int end = 10001;

    long sum = 0;
    for(int i0 = start; i0 < end; i0++) {
        sum += (long)arr[i0];
    }
    MPI_Send(&sum, 1, MPI_LONG, 0, 0, MPI_COMM_WORLD);
    } else { //其余进程

    int start = rank * patchSize;
    int end = start + patchSize;
    long sum = 0;
    for(int i0 = start; i0 < end; i0++) {
        sum += (long)arr[i0];
    }
    MPI_Send(&sum, 1, MPI_LONG, 0, 0, MPI_COMM_WORLD);
    }
    MPI_Finalize();
    return 0;
}