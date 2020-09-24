#include <iostream>
#include <stack>
#include <string>

struct Bracket
{
  Bracket (char type, int position):type (type), position (position)
  {
  }

  bool Matchc (char c)
  {
    if (type == '[' && c == ']')
      return true;
    if (type == '{' && c == '}')
      return true;
    if (type == '(' && c == ')')
      return true;
    return false;
  }

  char type;
  int position;
};

int
main ()
{
  std::string text;
  getline (std::cin, text);
int k=0;
  int flag = 0;
  std::stack < Bracket > opening_brackets_stack;
  for (int position = 0; position < text.length (); position++)
    {
      char next = text[position];
      Bracket b (next, position);
      if (next == '(' || next == '[' || next == '{')
	{
	  opening_brackets_stack.push (b);

	}

      if (next == ')' || next == ']' || next == '}')
	{
	  if (!opening_brackets_stack.empty ())
	    {
	      Bracket bx = opening_brackets_stack.top ();
	      if (bx.Matchc (next))
		opening_brackets_stack.pop ();
	      else
		{
		    opening_brackets_stack.push(b);
		    break;
		}
	    }
	  else
	    {
	        opening_brackets_stack.push(b);
	        break;
	    }
	}

    }

    Bracket by=opening_brackets_stack.top();
     k=by.position+1;

  if (opening_brackets_stack.empty ())
    std::cout << "Success";
  else
  std::cout << k;

  return 0;
}

