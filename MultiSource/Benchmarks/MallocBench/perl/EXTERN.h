/* $Header$
 *
 *    Copyright (c) 1989, Larry Wall
 *
 *    You may distribute under the terms of the GNU General Public License
 *    as specified in the README file that comes with the perl 3.0 kit.
 *
 * $Log$
 * Revision 1.1.2.1  2004/03/01 23:59:12  brukman
 * Merge from trunk
 *
 * Revision 1.1  2004/02/17 22:21:15  criswell
 * Initial commit of the perl Malloc Benchmark.  I've cheated a little by
 * generating the yacc output files and committing them directly, but it was
 * easier than disabling the Bison Voodoo that gets executed by default.
 *
 * Revision 4.0  91/03/20  00:58:26  lwall
 * 4.0 baseline.
 * 
 */

#undef EXT
#define EXT extern

#undef INIT
#define INIT(x)

#undef DOINIT
