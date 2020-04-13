
#include <vector>
#include <array>
#include <iostream>
#include<string>
using namespace std;

vector < vector <float> >  str_to_f(vector < vector <string> >  p) {

    int n = p.size();
    vector < vector <float> > x;
    x.resize(p.size());
    for (int i = 0; i<n; i++) {
        for (int j = 0; j<p[i].size(); j++) {
            if(p[i][j]=="")break;
            x[i].push_back(stof(p[i][j]));
        }
    }

    return x;
}

void myswap(float &a, float& b) {
    float x = a;
    a = b;
    b = x;
}

void bsort(vector < vector <float> > &  sortingelement) {
    int n = sortingelement.size(), m = sortingelement[0].size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (sortingelement[j][1]>sortingelement[j + 1][1]) {
                for (int k = 0; k < m; k++) {
                    myswap(sortingelement[j][k], sortingelement[j + 1][k]);
                }
            }
        }
    }
}

float waiting_time(vector < vector <string> >  in, vector < vector <string> >  out) { // data in , data out
    vector < vector <float> >  p, x;
    p = str_to_f(in);
    x = str_to_f(out);
    float r = 0, finish = 0, arrive = 0, burst = 0; // , turn_around = 0        // r =  f -ar -b
    int n = p.size(), m = x.size();
    for (int i = 0; i < n; i++) {
        arrive = p[i][1];
        burst = p[i][2];
        for (int j = m - 1; j >= 0; j--) {
            if (x[j][0] == p[i][0]) { finish = x[j][2]; break; }
        }
        r += finish - arrive - burst;
        // turn_around += finish - arrive ;
    }
    // turn_around = turn_around / n ;
    r = r / n;
    return r;
}

vector < vector <float> >  fcfs(vector < vector <string> >  in) {


    vector < vector <float> >  p = str_to_f(in);

    int n = p.size();

    vector < vector <float> >  x = p;
    bsort(p);
    float workstart = p[0][1]; //first p in time **************

    for (int i = 0; i < n; i++) {
        x[i][0] = p[i][0]; // pro_name = pro_name
        if (p[i][1] > workstart) { // if busy wait
            workstart = p[i][1];
        }
        x[i][1] = workstart;
        x[i][2] = p[i][2] + workstart;
        workstart = p[i][2] + workstart;
    }
    return x;
}
vector < vector <float> >  sjf_non_pre_emitive(vector < vector <string> >  in) {


    vector < vector <float> >  p = str_to_f(in);

    float least = 0;
    bsort(p);
    vector < vector <float> >  x = p;
    int n = p.size();
    float currenttime = p[0][1];
    for (int i = 0; i < n; i++) {
        if (i == n - 1) { // last iteration
            if (p[0][1] > currenttime) { currenttime = p[0][1]; }
            x[i][0] = p[0][0];
            x[i][1] = currenttime;
            x[i][2] = currenttime + p[0][2];
            break;
        }
        int e = 0, ee = 0, w = 0, ww = 0;//flags
        for (int j = 0; j < n - i; j++) {
            if (p[j][1] > currenttime) { e = j;  break; } // all p is done in current time then wait for the next p
            if (ee == 0) { least = p[j][2]; ee = 1; w = j; } // first p
            if (p[j][2] < least) { least = p[j][2]; w = j; }
        }
        if (ee == 0) { currenttime = p[e][1]; i--; continue; } // no p in current time
        x[i][0] = p[w][0];
        x[i][1] = currenttime;
        x[i][2] = currenttime + p[w][2];
        currenttime = currenttime + p[w][2];
        p.erase(p.begin() + w);

    }
    return x;
}
vector < vector <float> >  sjf_pre_emitive(vector < vector <string> >  in) {

    vector < vector <float> >  p = str_to_f(in);

    float least = 0;
    bsort(p);
    vector < vector <float> >  x, cc; //cc currnt time processes container
    float a = 0, b = 0, c = 0;
    int n = p.size(), t = 1;
    float currenttime = p[0][1];
    while (true) {
        if (p.size() == 1) {
            a = p[0][0];
            b = currenttime;
            c = p[0][2] + currenttime;
            x.push_back({ a,b,c });
            break;
        }
        int  ee = 0, w = 0;
        for (int j = 0; j < p.size(); j++) { // p time <= current time
            if (p[j][1] <= currenttime) { cc.push_back(p[j]); }
        }
        if (cc.empty()) { currenttime = p[0][1]; continue; }
        float  next = -1;
        for (int j = 0; j < p.size(); j++) {
            if (p[j][1] > currenttime) { next = p[j][1]; break; } //next p time in
        }
        for (int j = 0; j < cc.size(); j++) { // least time p
            if (ee == 0) { least = cc[j][2]; w = j; ee = 1; } //first iteration
            if (least > cc[j][2]) { least = cc[j][2]; w = j; } //least time p
        }
        a = cc[w][0];
        b = currenttime;
        if (next != -1) {
            if (cc[w][2] + currenttime > next) { c = next; } //not finished

            if (cc[w][2] + currenttime < next) { c = p[w][2] + currenttime; }//finished
        }
        else { c = p[w][2] + currenttime; }
        x.push_back({ a,b,c });
        p[w][2] = p[w][2] - (c - currenttime); // rest of burst time
        currenttime = c;
        if (p[w][2] == 0) { p.erase(p.begin() + w); }	//		delete on done
        cc.clear();
    }
    for (int j = 1; j <x.size(); j++) {
        if (x[j][0] == x[j - 1][0]) {
            x[j - 1][2] = x[j][2];
            x.erase(x.begin() + j);
            j--;
        }
    }
    return x;
}
vector < vector <float> >  priority_pre_emitive(vector < vector <string> >  in) {

    vector < vector <float> >  p = str_to_f(in);

    float least = 0;
    bsort(p);
    vector < vector <float> >  x, cc; //cc currnt time processes container
    float a = 0, b = 0, c = 0;
    int n = p.size(), t = 1;
    float currenttime = p[0][1];
    while (true) {
        if (p.size() == 1) {
            a = p[0][0];
            b = currenttime;
            c = p[0][2] + currenttime;
            x.push_back({ a,b,c });
            break;
        }
        int  ee = 0, w = 0;
        for (int j = 0; j < p.size(); j++) { // p time <= current time
            if (p[j][1] <= currenttime) { cc.push_back(p[j]); }
        }
        if (cc.empty()) { currenttime = p[0][1]; continue; }
        float  next = -1;
        for (int j = 0; j < p.size(); j++) {
            if (p[j][1] > currenttime) { next = p[j][1]; break; } //next p time in
        }
        for (int j = 0; j < cc.size(); j++) { // least time p
            if (ee == 0) { least = cc[j][3]; w = j; ee = 1; } //first iteration
            if (least > cc[j][3]) { least = cc[j][3]; w = j; } //least time p
        }
        a = cc[w][0];
        b = currenttime;
        if (next != -1) {
            if (cc[w][2] + currenttime > next) { c = next; } //not finished

            if (cc[w][2] + currenttime < next) { c = p[w][2] + currenttime; }//finished
        }
        else { c = p[w][2] + currenttime; }
        x.push_back({ a,b,c });
        p[w][2] = p[w][2] - (c - currenttime); // rest of burst time
        currenttime = c;
        if (p[w][2] == 0) { p.erase(p.begin() + w); }	//		delete on done
        cc.clear();
    }
    for (int j = 1; j <x.size(); j++) {
        if (x[j][0] == x[j - 1][0]) {
            x[j - 1][2] = x[j][2];
            x.erase(x.begin() + j);
            j--;
        }
    }

    return x;
}
vector < vector <float> >  priority_non_pre_emitive(vector < vector <string> >  in) {

    vector < vector <float> >  p = str_to_f(in);

    float least = 0;
    bsort(p);
    vector < vector <float> >  x = p;
    int n = p.size();
    float currenttime = p[0][1];
    for (int i = 0; i < n; i++) {
        if (i == n - 1) { // last iteration
            if (p[0][1] > currenttime) { currenttime = p[0][1]; }
            x[i][0] = p[0][0];
            x[i][1] = currenttime;
            x[i][2] = currenttime + p[0][2];
            break;
        }
        int e = 0, ee = 0, w = 0, ww = 0;//flags
        for (int j = 0; j < n - i; j++) {
            if (p[j][1] > currenttime) { e = j;  break; } // all p is done in current time then wait for the next p
            if (ee == 0) { least = p[j][3]; ee = 1; w = j; } // first p
            if (p[j][3] < least) { least = p[j][3]; w = j; }
        }
        if (ee == 0) { currenttime = p[e][1]; i--; continue; } // no p in current time
        x[i][0] = p[w][0];
        x[i][1] = currenttime;
        x[i][2] = currenttime + p[w][2];
        currenttime = currenttime + p[w][2];
        p.erase(p.begin() + w);

    }
    return x;
}


vector < vector <float> >  R_R(vector < vector <string> >  in, float time) {

    /*art = Arrival time,
    bt = Burst time,
    time_quantum= Quantum time
    tat = Turn around time,
    wt = Waiting time*/

    vector < vector <float> >  p = str_to_f(in);
        float least = 0;
        bsort(p);
        vector < vector <float> >  x, cc; //cc currnt time processes container
        float a = 0, b = 0, c = 0;
        int n = p.size(), start = 0, br = 0;
        float currenttime = p[0][1];
        while (true) {
            if (p.size() == 1) {
                a = p[0][0];
                b = ( p[0][1] > currenttime ) ? p[0][1] : currenttime ;
                c = p[0][2] + b;
                x.push_back({ a,b,c });
                break;
            }
            for (int j = 0; j < p.size(); j++) { // p time <= current time
                if (p[j][1] <= currenttime) { cc.push_back(p[j]); }
            }
            if (cc.empty()) { currenttime = p[0][1]; continue; }
            float  next = -1;
            for (int j = 0; j < p.size(); j++) {
                if (p[j][1] > currenttime) { next = p[j][1]; break; } //next p time in
            }
            int del = 0 ,looop=cc.size();
            for (int j = start; j < cc.size() ; j++) {
                a = cc[j][0];
                b = currenttime;
                if (cc[j][2] > time) { p[j][2] = p[j][2] - time; c = time + currenttime; currenttime = time + currenttime; } // not finished
                else {
                    c = cc[j][2] + currenttime;
                    currenttime = cc[j][2] + currenttime;
                    cc.erase(cc.begin() + j);
                    p.erase(p.begin() + j);
                    del++;
                    j--;
                }
                x.push_back({ a,b,c });
                if (cc.empty()) { break; }
                if (p.size() == 1) {  break; }
                if (p.size() == 0) { br = 1; break; }
            }

            if (currenttime >= next && next != -1) { start = looop - del; }
            else { start = 0; }
            if (br == 1) { break; }
            cc.clear();
        }

        for (int j = 1; j <x.size(); j++) {
            if (x[j][0] == x[j - 1][0]) {
                x[j - 1][2] = x[j][2];
                x.erase(x.begin() + j);
                j--;
            }
        }

        return x;
}

