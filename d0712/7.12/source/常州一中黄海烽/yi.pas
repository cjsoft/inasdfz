var
   a:array[0..10000000] of longint;
   n,i,ans,l,r:longint;
   ch:char;

procedure setin;
begin
    assign(input,'yi.in');
    assign(output,'yi.out');
    reset(input);rewrite(output);
end;

procedure outit;
begin
    close(input);close(output);
end;

procedure swap(var x,y:longint);var z:longint;begin z:=x;x:=y;y:=z;end;

procedure print;
var i:longint;
begin
    for i:=r downto l do write(a[i]);writeln;
end;

begin
    setin;
    n:=0;
    while not eoln do
    begin
        inc(n);
        read(ch);
        a[n]:=ord(ch)-48;
    end;
    for i:=1 to (n>>1) do swap(a[i],a[n-i+1]);
    l:=1;r:=n;ans:=0;
    while l<>r do
    begin
        while a[l]=0 do begin l:=l+1;inc(ans);end;
        if l=r then break;
        for i:=l to r do a[i]:=a[i]*3;inc(a[l]);
        for i:=l to r do if a[i]>1 then begin inc(a[i+1],a[i]>>1);a[i]:=a[i] and 1;end;
        while a[r+1]>0 do begin inc(r);inc(a[r+1],a[r]>>1);a[r]:=a[r] and 1;end;
        inc(ans);
    end;
    //writeln(ans1);writeln(ans2);writeln(ans1+ans2);
    writeln(ans);
    outit;
end.
