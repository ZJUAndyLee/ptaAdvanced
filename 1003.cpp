//有三个测试点没过 我用的是BFS实在找不到bug了等下次再来看吧
#include<iostream>
#include<queue>
using namespace std;

struct edge {
	int v,len;
	edge *p;
};

struct ver {
	int rt,path,tt,num_sp;
	bool ex;
	edge *n;

};

struct graph {
	ver *vx;
	int nv, ne,sp,ep;
};

edge *bdedge(int dt,int l){
	edge *eg = new edge;
	eg->v = dt;
	eg->len = l;
	eg->p = NULL;
	return eg;
}

void bdgraph(graph *g) {
	for (int i = 0; i < g->nv; i++) {
		cin >> g->vx[i].rt;
		g->vx[i].n = NULL;
		g->vx[i].path = 10000;
		g->vx[i].ex = 0;
		g->vx[i].tt = g->vx[i].rt;
		g->vx[i].num_sp = 0;
	}
	int tmp1, tmp2, tmp3;
	edge *tmp_e;
	for (int i = 0; i < g->ne; i++) {
		cin >> tmp1 >> tmp2 >> tmp3;
		if (!(g->vx)[tmp1].n)g->vx[tmp1].n = bdedge(tmp2, tmp3);
		else {
			tmp_e = g->vx[tmp1].n;
			while (tmp_e->p) tmp_e = tmp_e->p;
			tmp_e->p = bdedge(tmp2, tmp3);
		}
		if (!(g->vx)[tmp2].n)g->vx[tmp2].n = bdedge(tmp1, tmp3);
		else {
			tmp_e = g->vx[tmp2].n;
			while (tmp_e->p) tmp_e = tmp_e->p;
			tmp_e->p = bdedge(tmp1, tmp3);
		}
	}
}

void blgraph(graph *g) {
	queue<int> qe;
	edge *tmp;
	int tmp_v;
	g->vx[g->sp].ex = 1;
	g->vx[g->sp].path = 0;
	g->vx[g->sp].num_sp = 1;
	qe.push(g->sp);
	while (!qe.empty()) {
		tmp_v = qe.front();
		qe.pop();
		tmp = g->vx[tmp_v].n;
		while (tmp) {
			if (g->vx[tmp_v].path + tmp->len < g->vx[tmp->v].path) {
				g->vx[tmp->v].num_sp = g->vx[tmp_v].num_sp;
				g->vx[tmp->v].path = g->vx[tmp_v].path + tmp->len;
				g->vx[tmp->v].tt = g->vx[tmp_v].tt + g->vx[tmp->v].rt;
			}
			else if (g->vx[tmp_v].path + tmp->len == g->vx[tmp->v].path) {
				g->vx[tmp->v].num_sp = g->vx[tmp->v].num_sp + g->vx[tmp_v].num_sp;
				if (g->vx[tmp_v].tt + g->vx[tmp->v].rt > g->vx[tmp->v].tt)  g->vx[tmp->v].tt = g->vx[tmp_v].tt + g->vx[tmp->v].rt;
			}
			if (!g->vx[tmp->v].ex) { 
				qe.push(tmp->v);
				g->vx[tmp->v].ex = 1;
			}
			tmp = tmp->p;
		}
	}
}

int main() {
	graph *gh=new graph;
	cin >> gh->nv >> gh->ne >> gh->sp >> gh->ep;
	gh->vx = new ver[gh->nv];
	bdgraph(gh);
	blgraph(gh);
	cout << gh->vx[gh->ep].num_sp << " " << gh->vx[gh->ep].tt;
}
