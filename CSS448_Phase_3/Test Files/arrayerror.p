program arrayerror(input,output);

(* Illegal to have string subscripts in array *)
(* Error that must be caught through action code, passes grammar *)

type
  array1D = array ['abcd'..'xyz'] of integer;

var
  a: array1D;
  i: char;

begin
   for i := 'abcd' to 'xyz' do
   begin
      a[i] := i;
      write(a[i], " ");
   end;
   writeln;
end.

