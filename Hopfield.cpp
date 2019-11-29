#include <iostream>
#include <cstdlib>

using namespace std;

class Neuron
{
private:
    double w[70][70] = {
            {1,1,1,1}, {1,1,1,1}, {1,1,1,1}, {1,1,1,1}, {1,1,1,1},
            {1,1,1,1}, {1,1,1,1}, {1,1,1,1}, {1,1,1,1}, {1,1,1,1},
            {1,1,1,1}, {1,1,1,1}, {1,1,1,1}, {1,1,1,1}, {1,1,1,1},
            {1,1,1,1}, {1,1,1,1}, {1,1,1,1}, {1,1,1,1}, {1,1,1,1},
            {1,1,1,1}, {1,1,1,1}, {1,1,1,1}, {1,1,1,1}, {1,1,1,1},
            {1,1,1,1}, {1,1,1,1}, {1,1,1,1}, {1,1,1,1}, {1,1,1,1},
            {1,1,1,1}, {1,1,1,1}, {1,1,1,1}, {1,1,1,1}, {1,1,1,1},
            {1,1,1,1}, {1,1,1,1}, {1,1,1,1}, {1,1,1,1}, {1,1,1,1},
            {1,1,1,1}, {1,1,1,1}, {1,1,1,1}, {1,1,1,1}, {1,1,1,1},
            {1,1,1,1}, {1,1,1,1}, {1,1,1,1}, {1,1,1,1}, {1,1,1,1},
            {1,1,1,1}, {1,1,1,1}, {1,1,1,1}, {1,1,1,1}, {1,1,1,1},
            {1,1,1,1}, {1,1,1,1}, {1,1,1,1}, {1,1,1,1}, {1,1,1,1},
            {1,1,1,1}, {1,1,1,1}, {1,1,1,1}, {1,1,1,1}, {1,1,1,1},
            {1,1,1,1}, {1,1,1,1}, {1,1,1,1}, {1,1,1,1}, {1,1,1,1}
        };
    double target[10][70] = {
        {
            0, 0, 0, 0, 0, 0, 0, //0
            0, 1, 1, 1, 1, 1, 0,
            0, 1, 0, 0, 0, 1, 0, //1
            0, 1, 0, 1, 0, 1, 0, //3
            0, 1, 0, 1, 0, 1, 0, //4
            0, 1, 0, 1, 0, 1, 0, //5
            0, 1, 0, 1, 0, 1, 0, //6
            0, 1, 0, 0, 0, 1, 0, //7
            0, 1, 1, 1, 1, 1, 0, //8
            0, 0, 0, 0, 0, 0, 0  //9
        }, // 0
        {
            0, 0, 1, 0, 0, 0, 0, //0
            0, 1, 1, 0, 0, 0, 0,
            1, 1, 1, 0, 0, 0, 0, //1
            0, 0, 1, 0, 0, 0, 0, //3
            0, 0, 1, 0, 0, 0, 0, //4
            0, 0, 1, 0, 0, 0, 0, //5
            0, 0, 1, 0, 0, 0, 0, //6
            0, 0, 1, 0, 0, 0, 0, //7
            0, 0, 1, 0, 0, 0, 0, //8
            0, 1, 1, 1, 0, 0, 0  //9
        }, //1
        {
            0, 0, 1, 1, 1, 0, 0, //0
            0, 1, 1, 1, 1, 1, 0, //1
            0, 1, 1, 0, 1, 1, 1, //3
            0, 1, 0, 0, 0, 1, 1, //4
            0, 0, 0, 0, 1, 1, 0, //5
            0, 0, 0, 1, 1, 1, 0, //6
            0, 1, 1, 0, 0, 0, 0, //7
            0, 1, 1, 1, 1, 1, 1, //8
            0, 1, 1, 1, 1, 1, 1,  //9
            0, 0, 0, 0, 0, 0, 0
        }, //2
        {
            0, 0, 1, 1, 1, 0, 0, //0
            0, 1, 0, 0, 0, 1, 0, //1
            0, 1, 0, 0, 0, 1, 0, //3
            0, 0, 0, 0, 0, 1, 0, //4
            0, 0, 0, 0, 1, 1, 0, //5
            0, 0, 1, 1, 1, 0, 0,
            0, 0, 0, 0, 1, 1, 0, //6
            0, 1, 0, 0, 0, 1, 0, //7
            0, 1, 0, 0, 0, 1, 0, //8
            0, 0, 1, 1, 0, 0, 0  //9
        }, //3
        {
            1, 1, 0, 1, 1, 0, 0, //0
            1, 0, 0, 1, 0, 0, 0, //1
            1, 0, 0, 1, 0, 0, 0, //3
            1, 0, 0, 1, 0, 0, 0, //4
            1, 0, 0, 1, 0, 0, 0, //5
            1, 1, 1, 1, 1, 1, 1, //6
            0, 0, 0, 1, 0, 0, 0, //7
            0, 0, 0, 1, 0, 0, 0, //8
            0, 0, 0, 1, 1, 0, 0, //9
            0, 0, 0, 1, 1, 0, 0
        }, //4
        {
            1, 1, 1, 1, 1, 0, 0, //0
            1, 0, 0, 0, 1, 0, 0, //1
            1, 0, 0, 0, 0, 0, 0, //3
            1, 1, 1, 1, 0, 0, 0, //4
            0, 0, 1, 1, 1, 0, 0, //5
            0, 0, 0, 1, 1, 1, 0, //6
            0, 0, 0, 0, 1, 1, 0, //7
            0, 0, 0, 1, 1, 0, 0, //8
            1, 1, 1, 1, 1, 0, 0,  //9
            1, 1, 1, 1 ,0, 0, 0
        }, //5
        {
            0, 1, 1, 1, 1, 1, 1, //0
            0, 1, 1, 0, 0, 0, 0, //1
            0, 1, 1, 0, 0, 0, 0, //3
            0, 1, 1, 0, 0, 0, 0, //4
            0, 1, 1, 1, 1, 1, 1, //5
            0, 1, 0, 0, 0, 0, 1,
            0, 1, 0, 0, 0, 0, 1, //6
            0, 1, 0, 0, 0, 0, 1, //7
            0, 1, 0, 0, 0, 0, 1, //8
            0, 1, 1, 1, 1, 1, 1  //9
        }, //6
        {
            0, 1, 1, 1, 1, 1, 0, //0
            0, 1, 1, 0, 0, 1, 0, //1
            0, 1, 1, 0, 0, 1, 0, //3
            0, 1, 1, 0, 0, 1, 0, //4
            0, 0, 0, 0, 0, 1, 0, //5
            0, 0, 0, 0, 0, 1, 0, //6
            0, 0, 0, 0, 0, 1, 0, //7
            0, 0, 0, 0, 0, 1, 0, //8
            0, 0, 0, 0, 0, 1, 0,  //9
            0, 0, 0, 0, 0, 1, 0
        }, //7
        {
            0, 1, 1, 1, 1, 1, 0, //0
            1, 1, 0, 0, 0, 1, 1, //1
            1, 0, 0, 0, 0, 0, 1, //3
            1, 0, 0, 0, 0, 0, 1, //4
            1, 1, 1, 1, 1, 1, 1, //5
            0, 1, 1, 1, 1, 1, 0,
            1, 1, 0, 0, 0, 1, 1, //6
            1, 0, 0, 0, 0, 0, 1, //7
            1, 0, 0, 0, 0, 0, 1, //8
            0, 1, 1, 1, 1, 1, 0  //9
        }, //8
        {
            1, 1, 1, 1, 1, 1, 1, //0
            1, 0, 0, 0, 0, 0, 1, //1
            1, 0, 0, 0, 0, 0, 1, //3
            1, 0, 0, 0, 0, 0, 1, //4
            1, 1, 1, 1, 1, 1, 1, //5
            0, 0, 0, 0, 0, 0, 1,
            0, 0, 0, 0, 0, 0, 1, //6
            0, 0, 0, 0, 0, 0, 1, //7
            0, 0, 0, 0, 0, 0, 1, //8
            1, 1, 1, 1, 1, 1, 1  //9
        }, //9
    };


    double I[70][70] = {
        {0,},
    };

    double state[70] = {0.0,};
    double NET[70] = {0.0,};
    double threshold[70] = {0.0,};
public:
    Neuron() {
        for(int j=0; j<70; ++j)
            for(int i=0;i<70;++i){
                w[i][j] = 0;
                I[i][j] = 0;
        }

        for( int i=0; i<70; ++i) {
            I[i][i] = 1;
        }

    }
    void update();
    void noise10();
    void noise20();
    void noise30();
    void print_s();
    void Hopfield();
    bool match();
    void init(int in);
    void result();
};

void Neuron::noise10(){
    for(int i=0;i<7;++i) {
        int nois = rand()%70;
        if(this->state[nois] == 0.0)
            this->state[nois] = 1.0;
        else
            this->state[nois] = 0.0;
    }
}

void Neuron::noise20(){
    for(int i=0;i<14;++i) {
        int nois = rand()%70;
        if(this->state[nois] == 1.0)
            this->state[nois] = 0.0;
        else
            this->state[nois] = 1.0;
    }
}

void Neuron::noise30(){
    for(int i=0;i<21;++i) {
        int nois = rand()%70;
        if(this->state[nois] == 1.0)
            this->state[nois] = 0.0;
        else
            this->state[nois] = 1.0;
    }
}

void Neuron::print_s(){
    for(int i=0;i<70;++i){
        cout << (this->state)[i] << " ";
        if((i+1)%7 == 0)
            cout << endl;
    }
}

void Neuron::update(){
    for(int i=0;i<70;++i) {
        this->threshold[i] = 0;
        this->NET[i] = 0;
        for(int j=0;j<70;++j) {
            this->threshold[i] -= this->w[i][j]/2;
            this->NET[i] += this->w[i][j]*this->state[j];
        }
        this->NET[i] += this->threshold[i];
        if( this->NET[i] > 0.0 )
            this->state[i] = 1.0;
        else if( NET[i] < 0.0 )
            this->state[i] = 0.0;
        else
            this->state[i] = this->state[i];
    }
}

void Neuron::Hopfield()
{
    //this->compute(x);
    for(int i=0;i<70;++i) {
        for(int j=0;j<70;++j) {
            for(int k = 0; k<10; ++k)
            w[i][j] += (2.0*this->target[k][i]-1)*
                (2.0*this->target[k][j]-1) - this->I[i][j];
        }
    }
}

bool Neuron::match() {
    int i;
    int j;
    for(i=0;i<10;++i) {
        for(j=0;j<70;++j)
            if(this->target[i][j]!= state[j])
                break;
        if(j >= 70) {
            cout << "Matched!! : )" << endl;
            return true;
        }
    }
    return false;
}

void Neuron::init(int in)
{
    for(int i=0;i<70;++i){
        this->state[i] = this->target[in][i];
    }
}

void Neuron::result(){
    for(int i=0;i<70;++i) {
        if(this->state[i]>0.0)
            cout << "*";
        else
            cout << " ";
        if((i+1)%7 == 0)
            cout << endl;
    }
}

int main()
{
    int input = 0;
    int count = 0;

    while(1){
    cout << "Input number(0~9): ";
    cin >> input;

    Neuron neuron = Neuron();
    neuron.Hopfield();
    cout << "Making Hopfield..." << endl;
    neuron.init(input);
    neuron.noise10();
    cout << "10% noise----" << endl;
    while(!neuron.match() && count++ < 10) {
        neuron.result();
        neuron.update();
        cout << "-------------"<<endl;
    }
    if(count > 5)
        cout << "Miss matched :(" << endl;
    count = 0;
    neuron.result();

    neuron.init(input);
    neuron.noise20();
    cout << "20% noise----" << endl;
    while(!neuron.match() && count++ < 5) {
        neuron.update();
        neuron.result();
        cout << "-------------"<<endl;
    }
    if(count > 5)
        cout << "Miss matched :(" << endl;
    count = 0;
    neuron.result();

    neuron.init(input);
    neuron.noise30();
    cout << "30% noise----" << endl;
    while(!neuron.match() && count++ < 10) {
        neuron.update();
        neuron.result();
        cout << "-------------"<<endl;
    }
    if(count > 5)
        cout << "Miss matched :(" << endl;
    count = 0;
    neuron.result();
    }
    return 0;
}
