/* Type definitions for nondeterministic finite state machine for bison,
   Copyright (C) 1984 Bob Corbett and Free Software Foundation, Inc.

BISON is distributed in the hope that it will be useful, but WITHOUT ANY
WARRANTY.  No author or distributor accepts responsibility to anyone
for the consequences of using it or for whether it serves any
particular purpose or works at all, unless he says so in writing.
Refer to the BISON General Public License for full details.

Everyone is granted permission to copy, modify and redistribute BISON,
but only under the conditions described in the BISON General Public
License.  A copy of this license is supposed to have been given to you
along with BISON so you can know your rights and responsibilities.  It
should be in a file named COPYING.  Among other things, the copyright
notice and this notice must be preserved on all copies.

 In other words, you are welcome to use, share and improve this program.
 You are forbidden to forbid anyone else to use, share and improve
 what you give them.   Help stamp out software-hoarding!  */

/* These type definitions are used to represent a nondeterministic
   finite state machine that parses the specified grammar.
   This information is generated by the function generate_states
   in the file LR0.

Each state of the machine is described by a set of items --
particular positions in particular rules -- that are the possible
places where parsing could continue when the machine is in this state.
These symbols at these items are the allowable inputs that can follow now.

A core represents one state.  States are numbered in the number field.
When generate_states is finished, the starting state is state 0
and nstates is the number of states.  (A transition to a state
whose state number is nstates indicates termination.)  All the cores
are chained together and first_state points to the first one (state 0).

For each state there is a particular symbol which must have been the
last thing accepted to reach that state.  It is the accessing_symbol
of the core.

Each core contains a vector of nitems items which are the indices
in the ritems vector of the items that are selected in this state.

The link field is used for chaining buckets that hash states by
their itemsets.  This is for recognizing equivalent states and
combining them when the states are generated.

The two types of transitions are shifts (push the lookahead token
and read another) and reductions (combine the last n things on the
stack via a rule, replace them with the symbol that the rule derives,
and leave the lookahead token alone).  When the states are generated,
these transitions are represented in two other lists.

Each shifts structure describes the possible shift transitions out
of one state, the state whose number is in the number field.
The shifts structures are linked through next and first_shift points to them.
Each contains a vector of numbers of the states that shift transitions
can go to.  The accessing_symbol fields of those states' cores say what kind
of input leads to them.

A shift to state zero should be ignored.  Conflict resolution
deletes shifts by changing them to zero.

Each reductions structure describes the possible reductions at the state
whose number is in the number field.  The data is a list of nreds rules,
represented by their rule numbers.   first_reduction points to the list
of these structures.

Conflict resolution can decide that certain tokens in certain
states should explicitly be errors (for implementing %nonassoc).
For each state, the tokens that are errors for this reason
are recorded in an errs structure, which has the state number
in its number field.  The rest of the errs structure is full
of token numbers.

There is at least one shift transition present in state zero.
It leads to a next-to-final state whose accessing_symbol is
the grammar's start symbol.  The next-to-final state has one shift
to the final state, whose accessing_symbol is zero (end of input).
The final state has one shift, which goes to the termination state
(whose number is nstates, and for which there is no core structure).
The reason for the extra state at the end is to placate the parser's
strategy of making all decisions one token ahead of its actions.  */


typedef
  struct core
    {
      struct core *next;
      struct core *link;
      short number;
      short accessing_symbol;
      short nitems;
      short items[1];
    }
  core;



typedef
  struct shifts
    {
      struct shifts *next;
      short number;
      short nshifts;
      short shifts[1];
    }
  shifts;



typedef
  struct errs
    {
      short nerrs;
      short errs[1];
    }
  errs;



typedef
  struct reductions
    {
      struct reductions *next;
      short number;
      short nreds;
      short rules[1];
    }
  reductions;



extern int nstates;
extern core *first_state;
extern shifts *first_shift;
extern reductions *first_reduction;
