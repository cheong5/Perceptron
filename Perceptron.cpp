#include <iostream>
#include <cstdlib>

using namespace std;

class Neuron
{
public:
    double w[35][4] = {
            {1,1,1,1}, {1,1,1,1}, {1,1,1,1}, {1,1,1,1}, {1,1,1,1},
            {1,1,1,1}, {1,1,1,1}, {1,1,1,1}, {1,1,1,1}, {1,1,1,1},
            {1,1,1,1}, {1,1,1,1}, {1,1,1,1}, {1,1,1,1}, {1,1,1,1},
            {1,1,1,1}, {1,1,1,1}, {1,1,1,1}, {1,1,1,1}, {1,1,1,1},
            {1,1,1,1}, {1,1,1,1}, {1,1,1,1}, {1,1,1,1}, {1,1,1,1},
            {1,1,1,1}, {1,1,1,1}, {1,1,1,1}, {1,1,1,1}, {1,1,1,1},
            {1,1,1,1}, {1,1,1,1}, {1,1,1,1}, {1,1,1,1}, {1,1,1,1}
        };
    double target_value[10][4] =  {
        {0,0,0,0},
        {0,0,0,1},
        {0,0,1,0},
        {0,0,1,1},
        {0,1,0,0},

        {0,1,0,1},
        {0,1,1,0},
        {0,1,1,1},
        {1,0,0,0},
        {1,0,0,1}
    };

    double output[4] = {0,};
    double threshold = 0.0;
    double learn_rate = 0.1;


public:
    void result();
    double f(double x);
    void compute(double x[35]);
    void print_w();
    void Train(double x[35], int n);
    void reset();
    void noise();
};

void Neuron::noise(){
    for(int i=0;i<3;++i)
        this->target_value[rand()%11][rand()%11] = rand()%2;
}

void Neuron::reset() {
    for(int i=0;i<4;++i){
        for(int j=0;j<35;++j){
            (this->w)[j][i]=1;
        }
        this->output[i] = 0;
    }
}

void Neuron::print_w(){
    for(int i=0;i<4;++i){
        for(int j=0;j<35;++j){
            cout << (this->w)[j][i] << " ";
        }
        cout << endl;
    }
}

void Neuron::result(){
    for(int i=0;i<4;++i)
        cout << this->output[i] << " ";
    cout <<endl;
}

double Neuron::f(double x){
    double NET;
    if(x >= threshold)
        NET = 1.0;
    else
        NET = 0.0;
    return NET;
}

void Neuron::compute(double x[35])
{
    for(int i=0;i<4;++i) {
        double temp = 0.0;
        for(int j=0;j<35;++j)
            temp += x[j]*w[j][i];
        this->output[i] = f(temp);
    }
}

void Neuron::Train(double x[35],int n)
{
    this->compute(x);
    for(int i=0;i<4;++i){
        if(this->output[i] != this->target_value[n][i])
            for(int j=0;j<35;++j) {
                w[j][i] +=
                this->learn_rate*x[j]*(this->target_value[n][i] - this->output[i]);
            }
    }
}

int main()
{
    Neuron neuron = Neuron();
    int input;

    cout << "Making Perceptron..." << endl;

    double x[10][35] = {
        {
            0, 1, 1, 1, 0,
            1, 0, 0, 0, 1,
            1, 0, 0, 1, 1,
            1, 0, 1, 0, 1,
            1, 1, 0, 0, 1,
            1, 0, 0, 0, 1,
            0, 1, 1, 1, 0
        },
        {
            0, 1, 1, 0, 0,
            0, 0, 1, 0, 0,
            0, 0, 1, 0, 0,
            0, 0, 1, 0, 0,
            0, 0, 1, 0, 0,
            0, 0, 1, 0, 0,
            0, 1, 1, 1, 0
        },
        {
            0, 1, 1, 1, 0,
            1, 0, 0, 0, 1,
            0, 0, 0, 0, 1,
            0, 1, 1, 1, 0,
            1, 0, 0, 0, 0,
            1, 0, 0, 0, 0,
            1, 1, 1, 1, 1
        },
        {
            0, 1, 1, 1, 0,
            1, 0, 0, 0, 1,
            0, 0, 0, 0, 1,
            0, 0, 1, 1, 0,
            0, 0, 0, 0, 1,
            1, 0, 0, 0, 1,
            0, 1, 1, 1, 0
        },
        {
            1, 0, 0, 1, 0,
            1, 0, 0, 1, 0,
            1, 0, 0, 1, 0,
            1, 1, 1, 1, 1,
            0, 0, 0, 1, 0,
            0, 0, 0, 1, 0,
            0, 0, 0, 1, 0
        },
        {
            1, 1, 1, 1, 1,
            1, 0, 0, 0, 0,
            1, 0, 0, 0, 0,
            1, 1, 1, 1, 0,
            0, 0, 0, 0, 1,
            0, 0, 0, 0, 1,
            1, 1, 1, 1, 0
        },
        {
            0, 1, 1, 1, 1,
            1, 0, 0, 0, 0,
            1, 0, 0, 0, 0,
            1, 1, 1, 1, 0,
            1, 0, 0, 0, 1,
            1, 0, 0, 0, 1,
            0, 1, 1, 1, 0
        },
        {
            1, 1, 1, 1, 1,
            0, 0, 0, 0, 1,
            0, 0, 0, 0, 1,
            0, 0, 1, 1, 0,
            0, 1, 0, 0, 0,
            0, 1, 0, 0, 0,
            0, 1, 0, 0, 0,
        },
        {
            0, 1, 1, 1, 0,
            1, 0, 0, 0, 1,
            1, 0, 0, 0, 1,
            0, 1, 1, 1, 0,
            1, 0, 0, 0, 1,
            1, 0, 0, 0, 1,
            0, 1, 1, 1, 0
        },
        {
            0, 1, 1, 1, 0,
            1, 0, 0, 0, 1,
            1, 0, 0, 0, 1,
            0, 1, 1, 1, 1,
            0, 0, 0, 0, 1,
            1, 0, 0, 0, 1,
            0, 1, 1, 1, 0
        }
    };


    for(int j=0;j<1000;++j) {
       for(int i=0;i<10;++i){
            neuron.Train(x[i],i);
        }
    }
    while(1){
    cout << "Input number(0~9): ";
    cin >> input;

    neuron.compute(x[input]);
    neuron.result();

    //cout << "W[][]----------" << endl;
    //neuron.print_w();

    cout << "Input with noise(0~9): ";
    cin >> input;
    neuron.noise();
    neuron.compute(x[input]);
    neuron.result();
    }
    return 0;
}
