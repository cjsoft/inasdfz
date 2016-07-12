const n=100;m=2000;p=998244353;
const sav:array[0..7,1..10]of longint=
        ((1,0,0,0,0,0,0,0,0,0),(1,0,0,0,0,0,0,0,0,0),
        (2,6,0,0,0,0,0,0,0,0),
        (3,15,42,0,0,0,0,0,0,0),
        (6,42,156,420,0,0,0,0,0,0),
        (9,107,554,1910,5155,0,0,0,0,0),
      (30,780,7350,40590,161040,510510,1376340,0,0,0),
      (56,2128,26936,187880,902720,3363976,10429328,28133616,0,0)
      );
var a,ck,so:array[0..n]of longint;
    nn,mm,b1,b2,b3,b4:longint;
    t1,t2:text;
    ans:longint;
    b:array[0..m,0..m]of longint;
    //t1,t2:text;
procedure dfs(g1,g2:longint);
var f1,f2,d1:longint;
begin
  if g1=nn+1 then begin
    if g2=0 then begin
      for f1:=1 to nn do a[nn+f1]:=a[f1];
      for f1:=1 to nn do so[f1]:=nn+1-f1;
      for d1:=nn-1 downto 0 do for f1:=1 to nn do for f2:=1 to nn-1 do begin
        if (a[so[f2]+d1])< (a[so[f2+1]+d1]) then begin
          so[n]:=so[f2];
          so[f2]:=so[f2+1];
          so[f2+1]:=so[n];
        end;
      end;
      if so[1]=1 then begin
        inc(ans);
        //for f1:=1 to nn do write(a[f1]);
        //writeln;
      end;
    end;
    exit();
  end;
  for f1:=0 to g2 do begin
    if ck[(f1+g1)mod nn]=0 then begin
      ck[(f1+g1)mod nn]:=1;
      a[g1]:=f1;
      dfs(g1+1,g2-f1);
      ck[(f1+g1)mod nn]:=0;
    end;
  end;
end;

begin
  assign(t1,'jian.in');reset(t1);
  assign(t2,'jian.out');rewrite(t2);
  read(t1,nn,mm);
  if mm mod nn<>0 then writeln(t2,0) else begin
    if ((mm<=27)or((nn<=5)and (mm<=60) ))and true then begin
      ans:=0;
      dfs(1,mm);
      writeln(t2,ans);
    end else begin
      mm:=mm div nn;
      dec(nn);
      for b1:=1 to nn do b[nn,b1]:=sav[nn,b1];
      for b1:=nn-1 downto 1 do begin
        for b2:=nn-b1+1 to nn do b[b1,b2]:=b[b1+1,b2]-b[b1+1,b2-1];
      end;
      b[0,0]:=1;
      for b1:=1 to nn do b[0,0]:=int64(b[0,0])*b1 mod p;
      for b1:=0 to mm do begin
        b[0,b1]:=b[0,0];
      end;
      for b1:=1 to nn do for b2:=nn-b1+2 to mm do begin
        b[b1,b2]:=(b[b1-1,b2]+b[b1,b2-1])mod p;
      end;
      writeln(t2,b[nn,mm]);

    end;
  end;
  close(t1);
  close(t2);
end.
