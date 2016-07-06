var	p,ot,ne,g,q:array[0..100100]of longint;
	nl:array[0..100100]of boolean;
	e,n,casenum,root:longint;

procedure re;
begin
	assign(input,'ah.in');reset(input);
	assign(output,'ah.out');rewrite(output);
end;

procedure wr;
begin
	close(input);close(output);
end;

procedure clean;
begin
	e:=0;fillchar(g,sizeof(g),0);
	fillchar(nl,sizeof(nl),false);
end;

procedure add(x,y:longint);
begin
	inc(e);ot[e]:=y;ne[e]:=g[x];g[x]:=e;
end;

procedure start;
var	i,x:longint;
begin
	readln(n);
	clean;
	for i:=1 to n do begin read(x);if x=0 then root:=i else add(x,i);nl[x]:=true;end;
	for i:=1 to n do read(p[i]);
end;

procedure bfs;
var	head,tail,now,vi,vj,u:longint;
begin
	head:=0;tail:=1;q[1]:=root;now:=0;
	while head<tail do
	begin
		inc(head);vi:=q[head];u:=g[vi];
		while u>0 do
		begin
			vj:=ot[u];
			if (not nl[vj])and(p[vj]=-1) then begin p[vj]:=now;now:=now xor 1;end;
			if (nl[vj])and(p[vj]=-1) then begin inc(tail);q[tail]:=vj;end;
			u:=ne[u];
		end;
	end;
end;

procedure dfs0(fa,x:longint);
var	u,vj:longint;
	t:array[0..1]of longint;
begin
	if not nl[x] then exit;
	u:=g[x];t[0]:=0;t[1]:=0;
	while u>0 do
	begin
		vj:=ot[u];
		dfs0(x,vj);if p[vj]<>-1 then inc(t[p[vj]]);
		u:=ne[u];
	end;
	if t[1]>t[0] then p[x]:=1;
	if t[1]<t[0] then p[x]:=0;
end;

procedure dfs(fa,x:longint);
var	u,vj:longint;
	t:array[0..1]of longint;
begin
	if not nl[x] then exit;
	u:=g[x];t[0]:=0;t[1]:=0;
	while u>0 do
	begin
		vj:=ot[u];
		dfs(x,vj);if p[vj]<>-1 then inc(t[p[vj]]);
		u:=ne[u];
	end;
	if t[1]>t[0] then p[x]:=1 else p[x]:=0;
end;

begin
	re;
	readln(casenum);
	for casenum:=1 to casenum do
	begin
		start;
		//dfs0(0,root);
		bfs;
		dfs(0,root);
		if p[root]=0 then writeln(0) else writeln(-1);
	end;
	wr;
end.
