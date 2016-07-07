const n=1000+10;m=2000+10;
type waytype=record
	ne,va,tow:longint;
	end;
var 
	input:array[0..2,0..n]of longint;
	t1,t2:text;
	tt,nn,sz1,sz2,szpa:longint;
	b1,b2,b3,b4,b5:longint;ch:char;
	mp:array[0..n]of longint;
	wy:array[0..n*n*2]of waytype;szwy:longint;
	bx1,bx2,vis,dx:array[0..n*2]of longint;szpoint:longint;
	programans:longint;flow:longint;
	tf:array[0..m]of boolean;

procedure clearwy;
begin
	szwy:=1;
	fillchar(mp,sizeof(mp),0);
end;
procedure addpath(f1,f2,f3,f4:longint);
begin
	inc(szwy);
	wy[szwy].ne:=mp[f1];
	wy[szwy].va:=f3;
	wy[szwy].tow:=f2;
	mp[f1]:=szwy;
	inc(szwy);
	wy[szwy].ne:=mp[f2];
	wy[szwy].va:=f4;
	wy[szwy].tow:=f1;
	mp[f2]:=szwy;
end;
function bfs(ss,tt:longint):boolean;
var f1,f2,f3,f4:longint;
begin
	for f1:=0 to szpoint do bx2[f1]:=0;
	bx1[0]:=1;
	bx1[1]:=ss;
	bx2[ss]:=1;
	f1:=1;
	while (f1<=bx1[0]) do begin
		f2:=bx1[f1];
		f3:=mp[f2];
		while f3<>0 do begin
			if (wy[f3].va>0)and(bx2[wy[f3].tow]=0) then begin
				inc(bx1[0]);
				bx1[bx1[0]]:=wy[f3].tow;
				bx2[wy[f3].tow]:=bx1[0];
			end;
			f3:=wy[f3].ne;
		end;	
		inc(f1);
	end;
	for f1:=0 to szpoint do vis[f1]:=0;dx[0]:=0;
	if bx2[tt]=0 then exit(false) else exit(true);
end;
procedure dfs(pp:longint;var tt,tf,sig,ans:longint);
var f1,f2:longint;
begin
	if pp=tt then begin
		f2:=maxlongint;
		for f1:=1 to dx[0] do begin
			if wy[dx[f1]].va<f2 then f2:=wy[dx[f1]].va;
		end;
		for f1:=1 to dx[0] do begin
			dec(wy[dx[f1]].va,f2);
			inc(wy[dx[f1] xor 1].va,f2);
		end;
		ans:=ans+f2;
		tf:=1;exit;
	end;
	if tf=1 then exit;
	f1:=mp[pp];
	while f1<>0 do begin
		if (wy[f1].va>0)and(vis[wy[f1].tow]<sig)and(bx2[wy[f1].tow]>bx2[pp]) then begin
			if tf=1 then exit;
			vis[wy[f1].tow]:=sig;
			inc(dx[0]);
			dx[dx[0]]:=f1;
			dfs(wy[f1].tow,tt,tf,sig,ans);
			dx[dx[0]]:=0;
			dec(dx[0]);
		end;
		f1:=wy[f1].ne;
	end;
end;

function maxflow(ss,tt:longint):longint;
var ans,f1,f2,f3,f4:longint;
begin
	ans:=0;
	while bfs(ss,tt) do begin
		f2:=1;f1:=1;
		while f1=1 do begin
			f1:=0;
			dfs(ss,tt,f1,f2,ans);
			inc(f2);
		end;
	end;
	exit(ans);
end;
	
begin	
	assign(t1,'probe.in');reset(t1);
	assign(t2,'probe.out');rewrite(t2);
	readln(t1,tt);
	for b1:=1 to tt do begin
		readln(t1,nn);
		clearwy;programans:=0;flow:=0;
		flow:=0;sz1:=0;sz2:=0;szpa:=0;
		for b2:=1 to nn do begin
			read(t1,ch);
			if ch='E' then begin
				input[0,b2]:=1;
				inc(sz1);
				input[2,b2]:=sz1;
				addpath(nn+1,b2,1,0);
			end else begin
				input[0,b2]:=-1;
				inc(sz2);
				input[2,b2]:=sz2;
				addpath(b2,nn+2,1,0);
			end;	
			readln(t1,input[1,b2]);
		end;
		szpoint:=nn+2;
		for b2:=1 to nn-1 do if (input[0,b2]=1)and(input[1,b2]=0) then begin
			for b3:=b2+1 to b3 do if (input[0,b3]=-1)and(input[1,b3]=0) then begin
				addpath(b2,b3,1,0);
			end;
		end;
		for b2:=1 to nn-1 do if (input[0,b2]=1)and(input[1,b2]<>0) then begin
			b3:=b2+1;
			while b3<=nn do begin
				if input[0,b3]=-1 then begin
					addpath(b2,b3,1,0);
				end;
				if input[1,b2]=input[1,b3] then begin
					b3:=nn
				end;
				inc(b3);
			end;	
		end;
		for b3:=2 to nn do if (input[0,b3]=-1)and(input[1,b3]<>0) then begin
			b2:=b3-1;
			while b2>=1 do begin
				if (input[0,b2]=1)and(input[1,b2]=0) then begin
					addpath(b2,b3,1,0);
				end;
				if input[1,b2]=input[1,b3] then begin
					b2:=1;
				end;
				dec(b2);
			end;
		end;
		while sz1<sz2 do begin
			inc(szpoint);
			addpath(nn+1,szpoint,1,0);
			fillchar(tf,sizeof(tf),false);
			for b2:=1 to nn do begin
				if input[0,b2]=-1 then begin
					if (input[1,b2]=0)or(not(tf[input[1,b2]])) then begin
						addpath(szpoint,b2,1,0);
					end;
				end;
				if input[1,b2]<>0 then tf[input[1,b2]]:=true;
			end;
			inc(sz1);
		end;
		while sz1>sz2 do begin
			inc(szpoint);
			inc(programans);
			addpath(szpoint,nn+2,1,0);
			fillchar(tf,sizeof(tf),false);
			for b2:=nn downto 1 do begin
				if input[0,b2]=1 then begin
					if (input[1,b2]=0)or(not(tf[input[1,b2]])) then begin
						addpath(b2,szpoint,1,0);
					end;
				end;
				if input[1,b2]<>0 then tf[input[1,b2]]:=true;
			end;
			inc(sz2);
		end;
		flow:=maxflow(nn+1,nn+2);
		while (sz1+sz2<=nn*2)and(flow<sz1) do begin
			inc(szpoint);
			addpath(nn+1,szpoint,1,0);
			fillchar(tf,sizeof(tf),false);
			for b2:=1 to nn do begin
				if input[0,b2]=-1 then begin
					if (input[1,b2]=0)or(not(tf[input[1,b2]])) then begin
						addpath(szpoint,b2,1,0);
					end;
				end;
				if input[1,b2]<>0 then tf[input[1,b2]]:=true;
			end;
			inc(sz1);
			inc(szpoint);
			inc(programans);
			addpath(szpoint,nn+2,1,0);
			fillchar(tf,sizeof(tf),false);
			for b2:=nn downto 1 do begin
				if input[0,b2]=1 then begin
					if (input[1,b2]=0)or(not(tf[input[1,b2]])) then begin
						addpath(b2,szpoint,1,0);
					end;
				end;
				if input[1,b2]<>0 then tf[input[1,b2]]:=true;
			end;
			inc(sz2);
			flow:=flow+maxflow(nn+1,nn+2);
		end;
		if flow=sz1 then begin
			writeln(t2,programans);
		end else writeln(t2,'OTHER');
	end;
	close(t1);close(t2);
end.

