// A Bison parser, made by GNU Bison 3.0.4.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

// Take the name prefix into account.
#define yylex   decaflex

// First part of user declarations.
#line 4 "calc.yy" // lalr1.cc:404
 /*** C/C++ Declarations ***/

#include <stdio.h>
#include <string>
#include <vector>
#include "ast.h"
#include "scanner.h"
#include "driver.h"


#line 49 "parser.cc" // lalr1.cc:404

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

#include "parser.h"

// User implementation prologue.
#line 135 "calc.yy" // lalr1.cc:412


/* this "connects" the bison parser in the driver to the flex scanner class
 * object. it defines the yylex() function call to pull the next token from the
 * current lexer object of the driver context. */
#undef yylex
#define yylex driver.lexer->lex


#line 72 "parser.cc" // lalr1.cc:412


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (/*CONSTCOND*/ false)
# endif


// Suppress unused-variable warnings by "using" E.
#define YYUSE(E) ((void) (E))

// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << std::endl;                  \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yystack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE(Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void>(0)
# define YY_STACK_PRINT()                static_cast<void>(0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)


namespace decaf {
#line 158 "parser.cc" // lalr1.cc:479

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  Parser::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr = "";
        char const *yyp = yystr;

        for (;;)
          switch (*++yyp)
            {
            case '\'':
            case ',':
              goto do_not_strip_quotes;

            case '\\':
              if (*++yyp != '\\')
                goto do_not_strip_quotes;
              // Fall through.
            default:
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }


  /// Build a parser object.
  Parser::Parser (class Driver& driver_yyarg)
    :
#if YYDEBUG
      yydebug_ (false),
      yycdebug_ (&std::cerr),
#endif
      driver (driver_yyarg)
  {}

  Parser::~Parser ()
  {}


  /*---------------.
  | Symbol types.  |
  `---------------*/

  inline
  Parser::syntax_error::syntax_error (const location_type& l, const std::string& m)
    : std::runtime_error (m)
    , location (l)
  {}

  // basic_symbol.
  template <typename Base>
  inline
  Parser::basic_symbol<Base>::basic_symbol ()
    : value ()
  {}

  template <typename Base>
  inline
  Parser::basic_symbol<Base>::basic_symbol (const basic_symbol& other)
    : Base (other)
    , value ()
    , location (other.location)
  {
    value = other.value;
  }


  template <typename Base>
  inline
  Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const semantic_type& v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}


  /// Constructor for valueless symbols.
  template <typename Base>
  inline
  Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const location_type& l)
    : Base (t)
    , value ()
    , location (l)
  {}

  template <typename Base>
  inline
  Parser::basic_symbol<Base>::~basic_symbol ()
  {
    clear ();
  }

  template <typename Base>
  inline
  void
  Parser::basic_symbol<Base>::clear ()
  {
    Base::clear ();
  }

  template <typename Base>
  inline
  bool
  Parser::basic_symbol<Base>::empty () const
  {
    return Base::type_get () == empty_symbol;
  }

  template <typename Base>
  inline
  void
  Parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move(s);
    value = s.value;
    location = s.location;
  }

  // by_type.
  inline
  Parser::by_type::by_type ()
    : type (empty_symbol)
  {}

  inline
  Parser::by_type::by_type (const by_type& other)
    : type (other.type)
  {}

  inline
  Parser::by_type::by_type (token_type t)
    : type (yytranslate_ (t))
  {}

  inline
  void
  Parser::by_type::clear ()
  {
    type = empty_symbol;
  }

  inline
  void
  Parser::by_type::move (by_type& that)
  {
    type = that.type;
    that.clear ();
  }

  inline
  int
  Parser::by_type::type_get () const
  {
    return type;
  }


  // by_state.
  inline
  Parser::by_state::by_state ()
    : state (empty_state)
  {}

  inline
  Parser::by_state::by_state (const by_state& other)
    : state (other.state)
  {}

  inline
  void
  Parser::by_state::clear ()
  {
    state = empty_state;
  }

  inline
  void
  Parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  inline
  Parser::by_state::by_state (state_type s)
    : state (s)
  {}

  inline
  Parser::symbol_number_type
  Parser::by_state::type_get () const
  {
    if (state == empty_state)
      return empty_symbol;
    else
      return yystos_[state];
  }

  inline
  Parser::stack_symbol_type::stack_symbol_type ()
  {}


  inline
  Parser::stack_symbol_type::stack_symbol_type (state_type s, symbol_type& that)
    : super_type (s, that.location)
  {
    value = that.value;
    // that is emptied.
    that.type = empty_symbol;
  }

  inline
  Parser::stack_symbol_type&
  Parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    value = that.value;
    location = that.location;
    return *this;
  }


  template <typename Base>
  inline
  void
  Parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);

    // User destructor.
    YYUSE (yysym.type_get ());
  }

#if YYDEBUG
  template <typename Base>
  void
  Parser::yy_print_ (std::ostream& yyo,
                                     const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    symbol_number_type yytype = yysym.type_get ();
    // Avoid a (spurious) G++ 4.8 warning about "array subscript is
    // below array bounds".
    if (yysym.empty ())
      std::abort ();
    yyo << (yytype < yyntokens_ ? "token" : "nterm")
        << ' ' << yytname_[yytype] << " ("
        << yysym.location << ": ";
    YYUSE (yytype);
    yyo << ')';
  }
#endif

  inline
  void
  Parser::yypush_ (const char* m, state_type s, symbol_type& sym)
  {
    stack_symbol_type t (s, sym);
    yypush_ (m, t);
  }

  inline
  void
  Parser::yypush_ (const char* m, stack_symbol_type& s)
  {
    if (m)
      YY_SYMBOL_PRINT (m, s);
    yystack_.push (s);
  }

  inline
  void
  Parser::yypop_ (unsigned int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  Parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  Parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  Parser::debug_level_type
  Parser::debug_level () const
  {
    return yydebug_;
  }

  void
  Parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  inline Parser::state_type
  Parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - yyntokens_];
  }

  inline bool
  Parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  inline bool
  Parser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  Parser::parse ()
  {
    // State.
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

    /// The return value of parse ().
    int yyresult;

    // FIXME: This shoud be completely indented.  It is not yet to
    // avoid gratuitous conflicts when merging into the master branch.
    try
      {
    YYCDEBUG << "Starting parse" << std::endl;


    // User initialization code.
    #line 42 "calc.yy" // lalr1.cc:741
{
    // initialize the initial location object
    yyla.location.begin.filename = yyla.location.end.filename = &driver.streamname;
}

#line 537 "parser.cc" // lalr1.cc:741

    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, yyla);

    // A new symbol was pushed on the stack.
  yynewstate:
    YYCDEBUG << "Entering state " << yystack_[0].state << std::endl;

    // Accept?
    if (yystack_[0].state == yyfinal_)
      goto yyacceptlab;

    goto yybackup;

    // Backup.
  yybackup:

    // Try to take a decision without lookahead.
    yyn = yypact_[yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token: ";
        try
          {
            yyla.type = yytranslate_ (yylex (&yyla.value, &yyla.location));
          }
        catch (const syntax_error& yyexc)
          {
            error (yyexc);
            goto yyerrlab1;
          }
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.type_get ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.type_get ())
      goto yydefault;

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", yyn, yyla);
    goto yynewstate;

  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;

  /*-----------------------------.
  | yyreduce -- Do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_(yystack_[yylen].state, yyr1_[yyn]);
      /* If YYLEN is nonzero, implement the default value of the
         action: '$$ = $1'.  Otherwise, use the top of the stack.

         Otherwise, the following line sets YYLHS.VALUE to garbage.
         This behavior is undocumented and Bison users should not rely
         upon it.  */
      if (yylen)
        yylhs.value = yystack_[yylen - 1].value;
      else
        yylhs.value = yystack_[0].value;

      // Compute the default @$.
      {
        slice<stack_symbol_type, stack_type> slice (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, slice, yylen);
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
      try
        {
          switch (yyn)
            {
  case 2:
#line 160 "calc.yy" // lalr1.cc:859
    {(yylhs.value.proganode)=new ProgASTnode((yystack_[1].value.funcastanode));driver.ast.pRoot=(yylhs.value.proganode);}
#line 647 "parser.cc" // lalr1.cc:859
    break;

  case 3:
#line 162 "calc.yy" // lalr1.cc:859
    { (yylhs.value.mulvariableanode) = new VariablesASTnode();(yylhs.value.mulvariableanode)->push_back((yystack_[0].value.variableanode));}
#line 653 "parser.cc" // lalr1.cc:859
    break;

  case 4:
#line 163 "calc.yy" // lalr1.cc:859
    { (yylhs.value.mulvariableanode) = (yystack_[2].value.mulvariableanode);(yylhs.value.mulvariableanode)->push_back((yystack_[0].value.variableanode));}
#line 659 "parser.cc" // lalr1.cc:859
    break;

  case 5:
#line 165 "calc.yy" // lalr1.cc:859
    { (yylhs.value.variableanode) = new VariableASTnode(*(yystack_[0].value.stgval));}
#line 665 "parser.cc" // lalr1.cc:859
    break;

  case 6:
#line 166 "calc.yy" // lalr1.cc:859
    { (yylhs.value.variableanode) = new VariableASTnode(*(yystack_[3].value.stgval),(yystack_[1].value.intlitanode));}
#line 671 "parser.cc" // lalr1.cc:859
    break;

  case 7:
#line 168 "calc.yy" // lalr1.cc:859
    { (yylhs.value.varanode) = new VarbASTnode();(yylhs.value.varanode)->push_back(*(yystack_[0].value.stgval));}
#line 677 "parser.cc" // lalr1.cc:859
    break;

  case 8:
#line 169 "calc.yy" // lalr1.cc:859
    { (yylhs.value.varanode) = (yystack_[2].value.varanode);(yylhs.value.varanode)->push_back(*(yystack_[0].value.stgval));}
#line 683 "parser.cc" // lalr1.cc:859
    break;

  case 9:
#line 171 "calc.yy" // lalr1.cc:859
    {(yylhs.value.vardeclanode) = new VarbDeclnode(*(yystack_[2].value.stgval),(yystack_[1].value.varanode),";");}
#line 689 "parser.cc" // lalr1.cc:859
    break;

  case 10:
#line 172 "calc.yy" // lalr1.cc:859
    {(yylhs.value.vardeclanode) = new VarbDeclnode(*(yystack_[2].value.stgval),(yystack_[1].value.varanode),";");}
#line 695 "parser.cc" // lalr1.cc:859
    break;

  case 11:
#line 174 "calc.yy" // lalr1.cc:859
    {(yylhs.value.vardeclsmulanode) = new VarbDeclsnode();}
#line 701 "parser.cc" // lalr1.cc:859
    break;

  case 12:
#line 175 "calc.yy" // lalr1.cc:859
    {(yystack_[0].value.vardeclsmulanode)->push_back((yystack_[1].value.vardeclanode));(yylhs.value.vardeclsmulanode) = (yystack_[0].value.vardeclsmulanode);}
#line 707 "parser.cc" // lalr1.cc:859
    break;

  case 13:
#line 178 "calc.yy" // lalr1.cc:859
    { (yylhs.value.locateanode) = new LocationASTnode(*(yystack_[0].value.stgval));}
#line 713 "parser.cc" // lalr1.cc:859
    break;

  case 14:
#line 179 "calc.yy" // lalr1.cc:859
    { (yylhs.value.locateanode) = new LocationASTnode(*(yystack_[3].value.stgval),(yystack_[1].value.expranode));}
#line 719 "parser.cc" // lalr1.cc:859
    break;

  case 15:
#line 181 "calc.yy" // lalr1.cc:859
    {(yylhs.value.astanode) = (yystack_[0].value.intlitanode);}
#line 725 "parser.cc" // lalr1.cc:859
    break;

  case 16:
#line 182 "calc.yy" // lalr1.cc:859
    {(yylhs.value.astanode) = (yystack_[0].value.boollitanode);}
#line 731 "parser.cc" // lalr1.cc:859
    break;

  case 17:
#line 183 "calc.yy" // lalr1.cc:859
    {(yylhs.value.astanode) = (yystack_[0].value.charlitanode);}
#line 737 "parser.cc" // lalr1.cc:859
    break;

  case 18:
#line 185 "calc.yy" // lalr1.cc:859
    {(yylhs.value.intlitanode) = new IntLitASTnode((yystack_[0].value.integerVal));}
#line 743 "parser.cc" // lalr1.cc:859
    break;

  case 19:
#line 186 "calc.yy" // lalr1.cc:859
    {(yylhs.value.intlitanode) = new IntLitASTnode((yystack_[0].value.integerVal));}
#line 749 "parser.cc" // lalr1.cc:859
    break;

  case 20:
#line 188 "calc.yy" // lalr1.cc:859
    {(yylhs.value.boollitanode) = new BoolLitASTnode(true);}
#line 755 "parser.cc" // lalr1.cc:859
    break;

  case 21:
#line 189 "calc.yy" // lalr1.cc:859
    {(yylhs.value.boollitanode) = new BoolLitASTnode(false);}
#line 761 "parser.cc" // lalr1.cc:859
    break;

  case 22:
#line 191 "calc.yy" // lalr1.cc:859
    {(yylhs.value.charlitanode) = new CharLitASTnode(*(yystack_[0].value.stgval));}
#line 767 "parser.cc" // lalr1.cc:859
    break;

  case 23:
#line 194 "calc.yy" // lalr1.cc:859
    { (yylhs.value.expranode) = new Expr((yystack_[0].value.locateanode)); }
#line 773 "parser.cc" // lalr1.cc:859
    break;

  case 24:
#line 195 "calc.yy" // lalr1.cc:859
    { (yylhs.value.expranode) = new Expr((yystack_[0].value.astanode));}
#line 779 "parser.cc" // lalr1.cc:859
    break;

  case 25:
#line 196 "calc.yy" // lalr1.cc:859
    { (yylhs.value.expranode) = new Expr((yystack_[0].value.methodcallanode));}
#line 785 "parser.cc" // lalr1.cc:859
    break;

  case 26:
#line 197 "calc.yy" // lalr1.cc:859
    { (yylhs.value.expranode) = new Expr(new BinaryASTnode("+", (yystack_[2].value.expranode), (yystack_[0].value.expranode))); }
#line 791 "parser.cc" // lalr1.cc:859
    break;

  case 27:
#line 198 "calc.yy" // lalr1.cc:859
    { (yylhs.value.expranode) = new Expr(new BinaryASTnode("-", (yystack_[2].value.expranode), (yystack_[0].value.expranode))); }
#line 797 "parser.cc" // lalr1.cc:859
    break;

  case 28:
#line 199 "calc.yy" // lalr1.cc:859
    { (yylhs.value.expranode) = new Expr(new BinaryASTnode("*", (yystack_[2].value.expranode), (yystack_[0].value.expranode))); }
#line 803 "parser.cc" // lalr1.cc:859
    break;

  case 29:
#line 200 "calc.yy" // lalr1.cc:859
    { (yylhs.value.expranode) = new Expr(new BinaryASTnode("%", (yystack_[2].value.expranode), (yystack_[0].value.expranode))); }
#line 809 "parser.cc" // lalr1.cc:859
    break;

  case 30:
#line 201 "calc.yy" // lalr1.cc:859
    { (yylhs.value.expranode) = new Expr(new BinaryASTnode("/", (yystack_[2].value.expranode), (yystack_[0].value.expranode))); }
#line 815 "parser.cc" // lalr1.cc:859
    break;

  case 31:
#line 202 "calc.yy" // lalr1.cc:859
    { (yylhs.value.expranode) = new Expr(new BinaryASTnode("<", (yystack_[2].value.expranode), (yystack_[0].value.expranode))); }
#line 821 "parser.cc" // lalr1.cc:859
    break;

  case 32:
#line 203 "calc.yy" // lalr1.cc:859
    { (yylhs.value.expranode) = new Expr(new BinaryASTnode(">", (yystack_[2].value.expranode), (yystack_[0].value.expranode))); }
#line 827 "parser.cc" // lalr1.cc:859
    break;

  case 33:
#line 204 "calc.yy" // lalr1.cc:859
    { (yylhs.value.expranode) = new Expr(new BinaryASTnode("<=", (yystack_[2].value.expranode), (yystack_[0].value.expranode))); }
#line 833 "parser.cc" // lalr1.cc:859
    break;

  case 34:
#line 205 "calc.yy" // lalr1.cc:859
    { (yylhs.value.expranode) = new Expr(new BinaryASTnode(">=", (yystack_[2].value.expranode), (yystack_[0].value.expranode))); }
#line 839 "parser.cc" // lalr1.cc:859
    break;

  case 35:
#line 206 "calc.yy" // lalr1.cc:859
    { (yylhs.value.expranode) = new Expr(new BinaryASTnode("==", (yystack_[2].value.expranode), (yystack_[0].value.expranode))); }
#line 845 "parser.cc" // lalr1.cc:859
    break;

  case 36:
#line 207 "calc.yy" // lalr1.cc:859
    { (yylhs.value.expranode) = new Expr(new BinaryASTnode("!=", (yystack_[2].value.expranode), (yystack_[0].value.expranode))); }
#line 851 "parser.cc" // lalr1.cc:859
    break;

  case 37:
#line 208 "calc.yy" // lalr1.cc:859
    { (yylhs.value.expranode) = new Expr(new BinaryASTnode("&&", (yystack_[2].value.expranode), (yystack_[0].value.expranode))); }
#line 857 "parser.cc" // lalr1.cc:859
    break;

  case 38:
#line 209 "calc.yy" // lalr1.cc:859
    { (yylhs.value.expranode) = new Expr(new BinaryASTnode("||", (yystack_[2].value.expranode), (yystack_[0].value.expranode))); }
#line 863 "parser.cc" // lalr1.cc:859
    break;

  case 39:
#line 210 "calc.yy" // lalr1.cc:859
    { (yylhs.value.expranode) = new Expr(new UnaryASTnode("-", (yystack_[0].value.expranode))); }
#line 869 "parser.cc" // lalr1.cc:859
    break;

  case 40:
#line 211 "calc.yy" // lalr1.cc:859
    { (yylhs.value.expranode) = new Expr(new UnaryASTnode("!", (yystack_[0].value.expranode))); }
#line 875 "parser.cc" // lalr1.cc:859
    break;

  case 41:
#line 212 "calc.yy" // lalr1.cc:859
    { (yylhs.value.expranode) = new Expr((yystack_[1].value.expranode));}
#line 881 "parser.cc" // lalr1.cc:859
    break;

  case 42:
#line 214 "calc.yy" // lalr1.cc:859
    { (yylhs.value.fielddecanode) = new FieldDeclnode(*(yystack_[2].value.stgval),(yystack_[1].value.mulvariableanode),";");}
#line 887 "parser.cc" // lalr1.cc:859
    break;

  case 43:
#line 215 "calc.yy" // lalr1.cc:859
    { (yylhs.value.fielddecanode) = new FieldDeclnode(*(yystack_[2].value.stgval),(yystack_[1].value.mulvariableanode),";");}
#line 893 "parser.cc" // lalr1.cc:859
    break;

  case 44:
#line 217 "calc.yy" // lalr1.cc:859
    {(yylhs.value.methodnameanode) = new MethodNameASTnode(*(yystack_[0].value.stgval));}
#line 899 "parser.cc" // lalr1.cc:859
    break;

  case 45:
#line 219 "calc.yy" // lalr1.cc:859
    {(yylhs.value.stringlitanode)=new StringLitASTnode(*(yystack_[0].value.stgval));}
#line 905 "parser.cc" // lalr1.cc:859
    break;

  case 46:
#line 221 "calc.yy" // lalr1.cc:859
    {(yylhs.value.calloutargmanode) = new CalloutargASTnode((yystack_[0].value.expranode));}
#line 911 "parser.cc" // lalr1.cc:859
    break;

  case 47:
#line 222 "calc.yy" // lalr1.cc:859
    {(yylhs.value.calloutargmanode) = new CalloutargASTnode((yystack_[0].value.stringlitanode));}
#line 917 "parser.cc" // lalr1.cc:859
    break;

  case 48:
#line 224 "calc.yy" // lalr1.cc:859
    { (yylhs.value.calloutanode) = new CalloutASTnode();(yylhs.value.calloutanode)->push_back((yystack_[0].value.calloutargmanode));}
#line 923 "parser.cc" // lalr1.cc:859
    break;

  case 49:
#line 225 "calc.yy" // lalr1.cc:859
    { (yylhs.value.calloutanode) = (yystack_[2].value.calloutanode);(yylhs.value.calloutanode)->push_back((yystack_[0].value.calloutargmanode));}
#line 929 "parser.cc" // lalr1.cc:859
    break;

  case 50:
#line 227 "calc.yy" // lalr1.cc:859
    {(yylhs.value.methodargmanode) = new MethodargASTnode();}
#line 935 "parser.cc" // lalr1.cc:859
    break;

  case 51:
#line 228 "calc.yy" // lalr1.cc:859
    {(yylhs.value.methodargmanode) = new MethodargASTnode();
			 								 (yylhs.value.methodargmanode)->push_back((yystack_[0].value.expranode));}
#line 942 "parser.cc" // lalr1.cc:859
    break;

  case 52:
#line 230 "calc.yy" // lalr1.cc:859
    {(yylhs.value.methodargmanode) = (yystack_[2].value.methodargmanode);(yylhs.value.methodargmanode)->push_back((yystack_[0].value.expranode));}
#line 948 "parser.cc" // lalr1.cc:859
    break;

  case 53:
#line 232 "calc.yy" // lalr1.cc:859
    {(yylhs.value.argumentanode) = new ArgumentsASTnode();}
#line 954 "parser.cc" // lalr1.cc:859
    break;

  case 54:
#line 233 "calc.yy" // lalr1.cc:859
    {(yylhs.value.argumentanode) = new ArgumentsASTnode(*(yystack_[1].value.stgval),*(yystack_[0].value.stgval));}
#line 960 "parser.cc" // lalr1.cc:859
    break;

  case 55:
#line 234 "calc.yy" // lalr1.cc:859
    {(yylhs.value.argumentanode) = new ArgumentsASTnode(*(yystack_[1].value.stgval),*(yystack_[0].value.stgval));}
#line 966 "parser.cc" // lalr1.cc:859
    break;

  case 56:
#line 235 "calc.yy" // lalr1.cc:859
    {(yylhs.value.argumentanode) = new ArgumentsASTnode(*(yystack_[1].value.stgval),*(yystack_[0].value.stgval));
													(yylhs.value.argumentanode)->push_back((yystack_[3].value.argumentanode));}
#line 973 "parser.cc" // lalr1.cc:859
    break;

  case 57:
#line 237 "calc.yy" // lalr1.cc:859
    {(yylhs.value.argumentanode) = new ArgumentsASTnode(*(yystack_[1].value.stgval),*(yystack_[0].value.stgval));
		    										(yylhs.value.argumentanode)->push_back((yystack_[3].value.argumentanode));}
#line 980 "parser.cc" // lalr1.cc:859
    break;

  case 58:
#line 240 "calc.yy" // lalr1.cc:859
    {(yylhs.value.methodcallanode) = new MethodcallASTnode((yystack_[3].value.methodnameanode),(yystack_[1].value.methodargmanode));}
#line 986 "parser.cc" // lalr1.cc:859
    break;

  case 59:
#line 241 "calc.yy" // lalr1.cc:859
    {(yylhs.value.methodcallanode) = new MethodcallASTnode(*(yystack_[5].value.stgval),(yystack_[3].value.stringlitanode),(yystack_[1].value.calloutanode));}
#line 992 "parser.cc" // lalr1.cc:859
    break;

  case 60:
#line 242 "calc.yy" // lalr1.cc:859
    {(yylhs.value.methodcallanode) = new MethodcallASTnode(*(yystack_[3].value.stgval),(yystack_[1].value.stringlitanode));}
#line 998 "parser.cc" // lalr1.cc:859
    break;

  case 61:
#line 244 "calc.yy" // lalr1.cc:859
    {(yylhs.value.stmentanode) = new Statement((yystack_[0].value.statlocanode));}
#line 1004 "parser.cc" // lalr1.cc:859
    break;

  case 62:
#line 245 "calc.yy" // lalr1.cc:859
    {(yylhs.value.stmentanode) = new Statement((yystack_[0].value.methodsastanode));}
#line 1010 "parser.cc" // lalr1.cc:859
    break;

  case 63:
#line 246 "calc.yy" // lalr1.cc:859
    {(yylhs.value.stmentanode) = new Statement((yystack_[0].value.ifanode));}
#line 1016 "parser.cc" // lalr1.cc:859
    break;

  case 64:
#line 247 "calc.yy" // lalr1.cc:859
    {(yylhs.value.stmentanode) = new Statement((yystack_[0].value.ifelseanode));}
#line 1022 "parser.cc" // lalr1.cc:859
    break;

  case 65:
#line 248 "calc.yy" // lalr1.cc:859
    {(yylhs.value.stmentanode) = new Statement((yystack_[0].value.foranode));}
#line 1028 "parser.cc" // lalr1.cc:859
    break;

  case 66:
#line 249 "calc.yy" // lalr1.cc:859
    {(yylhs.value.stmentanode) = new Statement((yystack_[0].value.returnanode));}
#line 1034 "parser.cc" // lalr1.cc:859
    break;

  case 67:
#line 250 "calc.yy" // lalr1.cc:859
    {(yylhs.value.stmentanode) = new Statement((yystack_[0].value.termanode));}
#line 1040 "parser.cc" // lalr1.cc:859
    break;

  case 68:
#line 251 "calc.yy" // lalr1.cc:859
    {(yylhs.value.stmentanode) = new Statement((yystack_[0].value.blockanode));}
#line 1046 "parser.cc" // lalr1.cc:859
    break;

  case 69:
#line 253 "calc.yy" // lalr1.cc:859
    {(yylhs.value.statlocanode) = new StatementlocASTnode((yystack_[3].value.locateanode),*(yystack_[2].value.stgval),(yystack_[1].value.expranode));}
#line 1052 "parser.cc" // lalr1.cc:859
    break;

  case 70:
#line 254 "calc.yy" // lalr1.cc:859
    {(yylhs.value.statlocanode) = new StatementlocASTnode((yystack_[3].value.locateanode),*(yystack_[2].value.stgval),(yystack_[1].value.expranode));}
#line 1058 "parser.cc" // lalr1.cc:859
    break;

  case 71:
#line 255 "calc.yy" // lalr1.cc:859
    {(yylhs.value.statlocanode) = new StatementlocASTnode((yystack_[3].value.locateanode),*(yystack_[2].value.stgval),(yystack_[1].value.expranode));}
#line 1064 "parser.cc" // lalr1.cc:859
    break;

  case 72:
#line 257 "calc.yy" // lalr1.cc:859
    {(yylhs.value.methodsastanode) = new MethodstatASTnode((yystack_[1].value.methodcallanode));}
#line 1070 "parser.cc" // lalr1.cc:859
    break;

  case 73:
#line 259 "calc.yy" // lalr1.cc:859
    {(yylhs.value.ifanode) = new StatementifASTnode((yystack_[2].value.expranode),(yystack_[0].value.blocka));}
#line 1076 "parser.cc" // lalr1.cc:859
    break;

  case 74:
#line 261 "calc.yy" // lalr1.cc:859
    {(yylhs.value.ifelseanode) = new StatementifelseASTnode((yystack_[4].value.expranode),(yystack_[2].value.blocka),(yystack_[0].value.blocka));}
#line 1082 "parser.cc" // lalr1.cc:859
    break;

  case 75:
#line 263 "calc.yy" // lalr1.cc:859
    {(yylhs.value.foranode) = new StatementforASTnode(*(yystack_[5].value.stgval),(yystack_[3].value.expranode),(yystack_[1].value.expranode),(yystack_[0].value.blocka));}
#line 1088 "parser.cc" // lalr1.cc:859
    break;

  case 76:
#line 265 "calc.yy" // lalr1.cc:859
    {(yylhs.value.returnanode) = new StatementreturnexprASTnode((yystack_[1].value.expranode));}
#line 1094 "parser.cc" // lalr1.cc:859
    break;

  case 77:
#line 267 "calc.yy" // lalr1.cc:859
    {(yylhs.value.termanode) = new StatementterminateASTnode(*(yystack_[1].value.stgval));}
#line 1100 "parser.cc" // lalr1.cc:859
    break;

  case 78:
#line 268 "calc.yy" // lalr1.cc:859
    {(yylhs.value.termanode) = new StatementterminateASTnode(*(yystack_[1].value.stgval));}
#line 1106 "parser.cc" // lalr1.cc:859
    break;

  case 79:
#line 269 "calc.yy" // lalr1.cc:859
    {(yylhs.value.termanode) = new StatementterminateASTnode(*(yystack_[1].value.stgval));}
#line 1112 "parser.cc" // lalr1.cc:859
    break;

  case 80:
#line 271 "calc.yy" // lalr1.cc:859
    {(yylhs.value.blockanode) = new StatementblockASTnode((yystack_[0].value.blocka));}
#line 1118 "parser.cc" // lalr1.cc:859
    break;

  case 81:
#line 274 "calc.yy" // lalr1.cc:859
    {(yylhs.value.statementsanode) = new StatementsASTnode();}
#line 1124 "parser.cc" // lalr1.cc:859
    break;

  case 82:
#line 275 "calc.yy" // lalr1.cc:859
    {(yylhs.value.statementsanode) = (yystack_[0].value.statementsanode);(yylhs.value.statementsanode)->push_back((yystack_[1].value.stmentanode));}
#line 1130 "parser.cc" // lalr1.cc:859
    break;

  case 83:
#line 277 "calc.yy" // lalr1.cc:859
    {(yylhs.value.blocka) = new BlockASTnode((yystack_[2].value.vardeclsmulanode),(yystack_[1].value.statementsanode));}
#line 1136 "parser.cc" // lalr1.cc:859
    break;

  case 84:
#line 279 "calc.yy" // lalr1.cc:859
    {(yylhs.value.method_declanode) = new MethoddeclASTnode(*(yystack_[5].value.stgval),*(yystack_[4].value.stgval),(yystack_[2].value.argumentanode),(yystack_[0].value.blocka));}
#line 1142 "parser.cc" // lalr1.cc:859
    break;

  case 85:
#line 280 "calc.yy" // lalr1.cc:859
    {(yylhs.value.method_declanode) = new MethoddeclASTnode(*(yystack_[5].value.stgval),*(yystack_[4].value.stgval),(yystack_[2].value.argumentanode),(yystack_[0].value.blocka));}
#line 1148 "parser.cc" // lalr1.cc:859
    break;

  case 86:
#line 281 "calc.yy" // lalr1.cc:859
    {(yylhs.value.method_declanode) = new MethoddeclASTnode(*(yystack_[5].value.stgval),*(yystack_[4].value.stgval),(yystack_[2].value.argumentanode),(yystack_[0].value.blocka));}
#line 1154 "parser.cc" // lalr1.cc:859
    break;

  case 87:
#line 283 "calc.yy" // lalr1.cc:859
    {(yylhs.value.funcastanode) = new FunctionASTnode();}
#line 1160 "parser.cc" // lalr1.cc:859
    break;

  case 88:
#line 284 "calc.yy" // lalr1.cc:859
    {(yylhs.value.funcastanode) = (yystack_[0].value.funcastanode);(yylhs.value.funcastanode)->push_back((yystack_[1].value.fielddecanode));}
#line 1166 "parser.cc" // lalr1.cc:859
    break;

  case 89:
#line 285 "calc.yy" // lalr1.cc:859
    {(yylhs.value.funcastanode) = (yystack_[0].value.funcastanode);(yylhs.value.funcastanode)->push_back((yystack_[1].value.method_declanode));}
#line 1172 "parser.cc" // lalr1.cc:859
    break;


#line 1176 "parser.cc" // lalr1.cc:859
            default:
              break;
            }
        }
      catch (const syntax_error& yyexc)
        {
          error (yyexc);
          YYERROR;
        }
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;
      YY_STACK_PRINT ();

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, yylhs);
    }
    goto yynewstate;

  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        error (yyla.location, yysyntax_error_ (yystack_[0].state, yyla));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.type_get () == yyeof_)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:

    /* Pacify compilers like GCC when the user code never invokes
       YYERROR and the label yyerrorlab therefore never appears in user
       code.  */
    if (false)
      goto yyerrorlab;
    yyerror_range[1].location = yystack_[yylen - 1].location;
    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    goto yyerrlab1;

  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    {
      stack_symbol_type error_token;
      for (;;)
        {
          yyn = yypact_[yystack_[0].state];
          if (!yy_pact_value_is_default_ (yyn))
            {
              yyn += yyterror_;
              if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yyterror_)
                {
                  yyn = yytable_[yyn];
                  if (0 < yyn)
                    break;
                }
            }

          // Pop the current state because it cannot handle the error token.
          if (yystack_.size () == 1)
            YYABORT;

          yyerror_range[1].location = yystack_[0].location;
          yy_destroy_ ("Error: popping", yystack_[0]);
          yypop_ ();
          YY_STACK_PRINT ();
        }

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      error_token.state = yyn;
      yypush_ ("Shifting", error_token);
    }
    goto yynewstate;

    // Accept.
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;

    // Abort.
  yyabortlab:
    yyresult = 1;
    goto yyreturn;

  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack"
                 << std::endl;
        // Do not try to display the values of the reclaimed symbols,
        // as their printer might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
  }

  void
  Parser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what());
  }

  // Generate an error message.
  std::string
  Parser::yysyntax_error_ (state_type yystate, const symbol_type& yyla) const
  {
    // Number of reported tokens (one for the "unexpected", one per
    // "expected").
    size_t yycount = 0;
    // Its maximum.
    enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
    // Arguments of yyformat.
    char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];

    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yyla) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yyla.  (However, yyla is currently not documented for users.)
       - Of course, the expected token list depends on states to have
         correct lookahead information, and it depends on the parser not
         to perform extra reductions after fetching a lookahead from the
         scanner and before detecting a syntax error.  Thus, state
         merging (from LALR or IELR) and default reductions corrupt the
         expected token list.  However, the list is correct for
         canonical LR with one exception: it will still contain any
         token that will not be accepted due to an error action in a
         later state.
    */
    if (!yyla.empty ())
      {
        int yytoken = yyla.type_get ();
        yyarg[yycount++] = yytname_[yytoken];
        int yyn = yypact_[yystate];
        if (!yy_pact_value_is_default_ (yyn))
          {
            /* Start YYX at -YYN if negative to avoid negative indexes in
               YYCHECK.  In other words, skip the first -YYN actions for
               this state because they are default actions.  */
            int yyxbegin = yyn < 0 ? -yyn : 0;
            // Stay within bounds of both yycheck and yytname.
            int yychecklim = yylast_ - yyn + 1;
            int yyxend = yychecklim < yyntokens_ ? yychecklim : yyntokens_;
            for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
              if (yycheck_[yyx + yyn] == yyx && yyx != yyterror_
                  && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
                {
                  if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                    {
                      yycount = 1;
                      break;
                    }
                  else
                    yyarg[yycount++] = yytname_[yyx];
                }
          }
      }

    char const* yyformat = YY_NULLPTR;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
        YYCASE_(0, YY_("syntax error"));
        YYCASE_(1, YY_("syntax error, unexpected %s"));
        YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    std::string yyres;
    // Argument number.
    size_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += yytnamerr_ (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const signed char Parser::yypact_ninf_ = -66;

  const signed char Parser::yytable_ninf_ = -45;

  const short int
  Parser::yypact_[] =
  {
     -16,    -4,    34,    24,   -66,    -3,    49,    68,    86,    -3,
      -3,    79,    14,   -10,   -66,    25,    83,    92,   -66,   -66,
     -66,   101,   146,   -66,   114,   101,   -66,   101,   119,   128,
      29,   -66,   -66,   130,   122,   -66,    30,    33,   -66,   -66,
     161,   155,   -66,   155,   155,   173,   182,   179,   -66,   -66,
     -66,   -66,   -66,   191,   191,   179,    88,   -66,   187,   205,
     -66,    35,   142,   189,   196,   226,     5,   230,   -22,   238,
     254,    88,   -66,   -66,   -66,   -66,   -66,   -66,   -66,   -66,
     259,   -66,   -66,   274,   -66,    77,   276,   -66,    77,   270,
     -66,   -66,   -66,   -66,    77,    77,    77,   -66,   -66,   -66,
     -66,   -66,   121,   -66,   -66,    77,    77,    77,    77,   -66,
     -66,   -66,   -66,   240,   -66,    55,   207,    77,   222,    85,
     255,   -66,    77,    77,    77,    77,    77,    77,    77,    77,
      77,    77,    77,    77,    77,   139,   157,   175,   255,    73,
     -66,    66,   -66,   155,   192,   -66,    85,    85,   265,   265,
      -7,    -7,   255,    -7,    -7,   255,   255,    -7,    -7,   -66,
     -66,   -66,    77,   -66,   255,   -66,   -66,    87,   266,    77,
     255,    66,   -66,   155,   103,   -66,   -66,   -66
  };

  const unsigned char
  Parser::yydefact_[] =
  {
       0,     0,     0,     0,     1,    87,     0,     0,     0,    87,
      87,     0,     5,     0,     3,     5,     0,     0,    88,    89,
       2,    53,     0,    42,     0,    53,    43,    53,     0,     0,
       0,    18,    19,     0,     5,     4,     0,     0,    54,    55,
       0,     0,     6,     0,     0,     0,     0,    11,    84,    85,
      86,    56,    57,     0,     0,    11,    81,     7,     0,     0,
      12,    13,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    81,    61,    62,    63,    64,    65,    66,    67,    68,
       0,    80,     9,     0,    10,     0,     0,    79,     0,     0,
      20,    21,    22,    77,     0,     0,     0,    23,    24,    15,
      16,    17,     0,    25,    78,     0,     0,     0,    50,    72,
      82,    83,     8,     0,    45,     0,     0,     0,     0,    39,
      40,    76,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    51,     0,
      14,     0,    60,     0,     0,    41,    26,    27,    28,    30,
      31,    32,    29,    37,    38,    35,    36,    34,    33,    69,
      70,    71,     0,    58,    46,    47,    48,     0,    73,     0,
      52,     0,    59,     0,     0,    49,    74,    75
  };

  const short int
  Parser::yypgoto_[] =
  {
     -66,   -66,   305,   289,   261,   -66,   262,   -50,   -66,   292,
     -66,   -66,   -65,   -66,   -66,   232,   145,   -66,   -66,    59,
     -44,   -66,   -66,   -66,   -66,   -66,   -66,   -66,   -66,   -66,
     248,   -41,   -66,   260
  };

  const short int
  Parser::yydefgoto_[] =
  {
      -1,     2,    13,    14,    58,    55,    56,    97,    98,    99,
     100,   101,   164,     9,    69,   165,   166,   167,   139,    30,
     103,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    10,    11
  };

  const short int
  Parser::yytable_[] =
  {
      48,   102,    49,    50,     6,     7,    68,    23,    24,    31,
      32,    61,    70,   105,     1,    62,    90,    91,    92,     3,
     113,    68,    93,   116,    94,   106,   107,    70,     8,   118,
     119,   120,   128,    21,     4,    22,   131,   132,    95,     5,
     135,   136,   137,   138,    25,    96,    22,    40,    40,    41,
      43,    40,   144,    44,   -44,    12,    85,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
      31,    32,    61,   141,    15,   142,    62,    90,    91,    92,
     114,    31,    32,    61,    36,    94,    37,    62,    90,    91,
      92,   162,    17,   163,    61,    20,    94,   170,    62,    95,
      26,    24,   168,    47,   174,   171,    96,   172,    28,    29,
      95,    27,    63,    64,    65,    66,    67,    96,    47,   124,
      34,   125,   126,   127,   128,    38,   129,   130,   131,   132,
     133,   134,   176,   177,    39,   122,   123,   124,   121,   125,
     126,   127,   128,    22,   129,   130,   131,   132,   133,   134,
      31,    32,    42,   122,   123,   124,   159,   125,   126,   127,
     128,    86,   129,   130,   131,   132,   133,   134,    45,    46,
      47,   122,   123,   124,   160,   125,   126,   127,   128,    51,
     129,   130,   131,   132,   133,   134,    53,    54,    52,   122,
     123,   124,   161,   125,   126,   127,   128,    57,   129,   130,
     131,   132,   133,   134,    82,    83,    87,   122,   123,   124,
     169,   125,   126,   127,   128,    88,   129,   130,   131,   132,
     133,   134,    84,    83,   122,   123,   124,   143,   125,   126,
     127,   128,    89,   129,   130,   131,   132,   133,   134,   122,
     123,   124,   145,   125,   126,   127,   128,   104,   129,   130,
     131,   132,   133,   134,   122,   123,   124,   108,   125,   126,
     127,   128,   140,   129,   130,   131,   132,   133,   134,    18,
      19,   109,   122,   123,   124,   111,   125,   126,   127,   128,
     112,   129,   130,   131,   132,   133,   134,   122,   123,   124,
     114,   125,   126,   127,   128,   173,   129,   130,   131,   132,
     133,   134,   126,   127,   128,   117,   129,   130,   131,   132,
     133,   134,    16,    35,    33,    59,   175,    60,   115,   110
  };

  const unsigned char
  Parser::yycheck_[] =
  {
      41,    66,    43,    44,     7,     8,    56,    17,    18,     4,
       5,     6,    56,    35,    30,    10,    11,    12,    13,    23,
      85,    71,    17,    88,    19,    47,    48,    71,    31,    94,
      95,    96,    39,    19,     0,    21,    43,    44,    33,    15,
     105,   106,   107,   108,    19,    40,    21,    18,    18,    20,
      20,    18,   117,    20,    19,     6,    21,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
       4,     5,     6,    18,     6,    20,    10,    11,    12,    13,
      14,     4,     5,     6,    25,    19,    27,    10,    11,    12,
      13,    18,     6,    20,     6,    16,    19,   162,    10,    33,
      17,    18,   143,    15,   169,    18,    40,    20,     7,     8,
      33,    19,    24,    25,    26,    27,    28,    40,    15,    34,
       6,    36,    37,    38,    39,     6,    41,    42,    43,    44,
      45,    46,   173,   174,     6,    32,    33,    34,    17,    36,
      37,    38,    39,    21,    41,    42,    43,    44,    45,    46,
       4,     5,    22,    32,    33,    34,    17,    36,    37,    38,
      39,    19,    41,    42,    43,    44,    45,    46,     7,     8,
      15,    32,    33,    34,    17,    36,    37,    38,    39,     6,
      41,    42,    43,    44,    45,    46,     7,     8,     6,    32,
      33,    34,    17,    36,    37,    38,    39,     6,    41,    42,
      43,    44,    45,    46,    17,    18,    17,    32,    33,    34,
      18,    36,    37,    38,    39,    19,    41,    42,    43,    44,
      45,    46,    17,    18,    32,    33,    34,    20,    36,    37,
      38,    39,     6,    41,    42,    43,    44,    45,    46,    32,
      33,    34,    20,    36,    37,    38,    39,    17,    41,    42,
      43,    44,    45,    46,    32,    33,    34,    19,    36,    37,
      38,    39,    22,    41,    42,    43,    44,    45,    46,     9,
      10,    17,    32,    33,    34,    16,    36,    37,    38,    39,
       6,    41,    42,    43,    44,    45,    46,    32,    33,    34,
      14,    36,    37,    38,    39,    29,    41,    42,    43,    44,
      45,    46,    37,    38,    39,    35,    41,    42,    43,    44,
      45,    46,     7,    24,    22,    54,   171,    55,    86,    71
  };

  const unsigned char
  Parser::yystos_[] =
  {
       0,    30,    50,    23,     0,    15,     7,     8,    31,    62,
      81,    82,     6,    51,    52,     6,    51,     6,    82,    82,
      16,    19,    21,    17,    18,    19,    17,    19,     7,     8,
      68,     4,     5,    58,     6,    52,    68,    68,     6,     6,
      18,    20,    22,    20,    20,     7,     8,    15,    80,    80,
      80,     6,     6,     7,     8,    54,    55,     6,    53,    53,
      55,     6,    10,    24,    25,    26,    27,    28,    56,    63,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    17,    18,    17,    21,    19,    17,    19,     6,
      11,    12,    13,    17,    19,    33,    40,    56,    57,    58,
      59,    60,    61,    69,    17,    35,    47,    48,    19,    17,
      79,    16,     6,    61,    14,    64,    61,    35,    61,    61,
      61,    17,    32,    33,    34,    36,    37,    38,    39,    41,
      42,    43,    44,    45,    46,    61,    61,    61,    61,    67,
      22,    18,    20,    20,    61,    20,    61,    61,    61,    61,
      61,    61,    61,    61,    61,    61,    61,    61,    61,    17,
      17,    17,    18,    20,    61,    64,    65,    66,    80,    18,
      61,    18,    20,    29,    61,    65,    80,    80
  };

  const unsigned char
  Parser::yyr1_[] =
  {
       0,    49,    50,    51,    51,    52,    52,    53,    53,    54,
      54,    55,    55,    56,    56,    57,    57,    57,    58,    58,
      59,    59,    60,    61,    61,    61,    61,    61,    61,    61,
      61,    61,    61,    61,    61,    61,    61,    61,    61,    61,
      61,    61,    62,    62,    63,    64,    65,    65,    66,    66,
      67,    67,    67,    68,    68,    68,    68,    68,    69,    69,
      69,    70,    70,    70,    70,    70,    70,    70,    70,    71,
      71,    71,    72,    73,    74,    75,    76,    77,    77,    77,
      78,    79,    79,    80,    81,    81,    81,    82,    82,    82
  };

  const unsigned char
  Parser::yyr2_[] =
  {
       0,     2,     5,     1,     3,     1,     4,     1,     3,     3,
       3,     0,     2,     1,     4,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     2,
       2,     3,     3,     3,     1,     1,     1,     1,     1,     3,
       0,     1,     3,     0,     2,     2,     4,     4,     4,     6,
       4,     1,     1,     1,     1,     1,     1,     1,     1,     4,
       4,     4,     2,     5,     7,     7,     3,     2,     2,     2,
       1,     0,     2,     4,     6,     6,     6,     0,     2,     2
  };



  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const Parser::yytname_[] =
  {
  "END", "error", "$undefined", "EOL", "NUM", "HEX", "ID", "INT",
  "BOOLEAN", "CHAR", "CALLOUT", "TRUE", "FALSE", "CHARLIT", "STRLIT",
  "LFB", "RFB", "SEMICOL", "COMMA", "LB", "RB", "LSB", "RSB", "PROGRAM",
  "CONTINUE", "IF", "FOR", "RETURN", "BREAK", "ELSE", "CLASS", "VOID",
  "PLUS", "MINUS", "MUL", "EQ", "DIV", "LT", "GT", "MOD", "NOT", "AND",
  "OR", "EQEQ", "NOTEQ", "GTEQ", "LTEQ", "PLUSEQ", "MINUSEQ", "$accept",
  "program", "var", "vari", "vars", "vardecl", "vardeclsmul", "location",
  "literal", "int_literal", "bool_literal", "char_literal", "expr",
  "field_decl", "method_name", "string_literal", "calloutarg", "callout",
  "method_arg", "arguments", "method_call", "statement", "statement1",
  "statement2", "statement3", "statement4", "statement5", "statement6",
  "statement7", "statement8", "statements", "block", "method_decl",
  "function", YY_NULLPTR
  };

#if YYDEBUG
  const unsigned short int
  Parser::yyrline_[] =
  {
       0,   160,   160,   162,   163,   165,   166,   168,   169,   171,
     172,   174,   175,   178,   179,   181,   182,   183,   185,   186,
     188,   189,   191,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   214,   215,   217,   219,   221,   222,   224,   225,
     227,   228,   230,   232,   233,   234,   235,   237,   240,   241,
     242,   244,   245,   246,   247,   248,   249,   250,   251,   253,
     254,   255,   257,   259,   261,   263,   265,   267,   268,   269,
     271,   274,   275,   277,   279,   280,   281,   283,   284,   285
  };

  // Print the state stack on the debug stream.
  void
  Parser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << i->state;
    *yycdebug_ << std::endl;
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  Parser::yy_reduce_print_ (int yyrule)
  {
    unsigned int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):" << std::endl;
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG

  // Symbol number corresponding to token number t.
  inline
  Parser::token_number_type
  Parser::yytranslate_ (int t)
  {
    static
    const token_number_type
    translate_table[] =
    {
     0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48
    };
    const unsigned int user_token_number_max_ = 303;
    const token_number_type undef_token_ = 2;

    if (static_cast<int>(t) <= yyeof_)
      return yyeof_;
    else if (static_cast<unsigned int> (t) <= user_token_number_max_)
      return translate_table[t];
    else
      return undef_token_;
  }


} // decaf
#line 1744 "parser.cc" // lalr1.cc:1167
#line 288 "calc.yy" // lalr1.cc:1168



void decaf::Parser::error(const Parser::location_type& l, const std::string& m)
{
    driver.error(l, m);
}
