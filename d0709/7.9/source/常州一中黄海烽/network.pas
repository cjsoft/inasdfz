var
   ot,ne,cap,g,dep,fa:array[0..11000] of longint;
   a:array[0..5010,0..5010] of longint;
   u,v,w,k,i,j,n,q,e,ans:longint;

procedure add(x,y,z:longint);
begin
    ot[e]:=y;ne[e]:=g[x];cap[e]:=z;g[x]:=e;e:=e+1;
    ot[e]:=x;ne[e]:=g[y];cap[e]:=z;g[y]:=e;e:=e+1;
end;

procedure dfs(x,l:longint);
var p,y:longint;
begin
    p:=g[x];
    while p<>-1 do
    begin
        y:=ot[p];
        if y<>l then
        begin
            dep[y]:=dep[x]+1;
            fa[y]:=x;
            dfs(y,x);
        end;
        p:=ne[p];
    end;
end;

procedure swap(var x,y:longint);var z:longint;begin z:=x;x:=y;y:=z;end;

function gcd(x,y:longint):longint;
var z:longint;
begin
    if x>y then swap(x,y);
    while y<>0 do
    begin
        z:=x mod y;
        x:=y;y:=z;
    end;
    exit(x);
end;


function lca(x,y:longint):longint;
begin
    if dep[x]<dep[y] then swap(x,y);
    if dep[x]>dep[y] then begin lca:=a[x,fa[x]];x:=fa[x];end
    else begin lca:=gcd(a[x,fa[x]],a[y,fa[y]]);x:=fa[x];y:=fa[y];end;
    while dep[x]>dep[y] do
    begin
        lca:=gcd(lca,a[x,fa[x]]);
        x:=fa[x];
    end;
    while x<>y do
    begin
        lca:=gcd(lca,a[x,fa[x]]);
        lca:=gcd(lca,a[y,fa[y]]);
        x:=fa[x];y:=fa[y];
    end;
end;

procedure getans;
var i,j:longint;
begin
    ans:=0;
    for i:=1 to n-1 do
     for j:=i+1 to n do
      if lca(i,j)=1 then inc(ans);
    writeln(ans);
end;

begin
    assign(input,'network.in');
    assign(output,'network.out');
    reset(input);rewrite(output);
    read(n);
    e:=1;fillchar(g,sizeof(g),255);
    for i:=1 to n-1 do
    begin
        read(u,v,w);
        a[u,v]:=w;a[v,u]:=w;
        add(u,v,w);
    end;
    dep[n div 2]:=0;fa[n div 2]:=0;
    dfs(n div 2,-1);
    getans;
    read(q);
    for i:=1 to q do
    begin
        read(k,w);
        cap[k*2-1]:=w;cap[k*2]:=w;
        u:=ot[k*2-1];v:=ot[k*2];
        a[u,v]:=w;a[v,u]:=w;
        getans;
    end;
    close(input);close(output);
end.