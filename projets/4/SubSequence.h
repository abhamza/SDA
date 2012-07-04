#include <stddef.h>

/***********************************************************************
 * A sequence S=<x_0, ..., x_m-1> is an ordered list of integer
 * values.  A subsequence (x_{i_1}, ..., x_{i_k}) of S is an ordered
 * list of elements of S where 0 <= i_1 <= ... <= i_k <m. A
 * subsequence is contiguous if i_{j + 1} == i_{j} + 1. A subsequence
 * is constant if all its elements are equal, x_{i_1}==x_{i_2}==
 * ...==x_{i_k}.
 *
 * In what follows, a sequence is represented by an array of int.
 ***********************************************************************/
 
#ifndef _SUBSEQUENCE_H_

/***********************************************************************
 * Returns the indices delimiting a largest constant contiguous
 * subsequence in a sequence.  This functions must use EXHAUSTIVE
 * SEARCH.
 *
 * PARAMETERS
 * sequence       Pointer to an integer vector
 * sequenceLength Size of the sequence
 *
 * RETURN-by-PARAMETERS
 * lowerIndex     lower index of the subsequence
 * upperIndex     upper index of the subsequence
 *
 * RETURN
 * non-0          if error
 ***********************************************************************/
int getCstContSubSeqES(const int* sequence, size_t sequenceLength,
			    size_t* lowerIndex, size_t* upperIndex);

/***********************************************************************
 * Returns the indices delimiting a largest constant contiguous
 * subsequence in a sequence.  This function must use a
 * DIVIDE-AND-CONQUER strategy.
 *
 * PARAMETERS
 * sequence       Pointer to an integer vector
 * sequenceLength Size of the sequence
 *
 * RETURN-by-PARAMETERS
 * lowerIndex     lower index of the subsequence
 * upperIndex     upper index of the subsequence
 *
 * RETURN
 * non-0          if error
 ***********************************************************************/
int getCstContSubSeqDC(const int* sequence, size_t sequenceLength,
		       size_t* lowerIndex, size_t* upperIndex);

/***********************************************************************
 * Returns the length and the constant value of a largest constant
 * subsequence in a sequence. The subsequence is NOT necessarily
 * contiguous. The function must be implemented following a DYNAMIC
 * PROGRAMMING approach.
 *
 * PARAMETERS
 * sequence       Pointer to an integer vector
 * sequenceLength Size of the sequence
 *
 * RETURN-by-PARAMETERS
 * length         The length of the sub-sequence
 * value          The constant value of the sub-sequence
 *
 * RETURN
 * non-0          if error
 ***********************************************************************/
int getCstSubSeqDP(const int* sequence, size_t sequenceLength,
		   size_t* length, int* value);

/***********************************************************************
 * Returns the length and the constant value of a largest constant
 * contiguous subsequence common to two given sequences. The function
 * must be implemented following a DYNAMIC PROGRAMMING approach.
 *
 * PARAMETERS
 * fisrtSequence        Pointer to the first integer vector
 * firstSequenceLength  Size of the first sequence
 * secondSequence       Pointer to the second integer vector
 * secondSequenceLength Size of the second sequence
 *
 * RETURN-by-PARAMETERS
 * length         The length of the sub-sequence
 * value          The constant value of the sub-sequence
 *
 * RETURN
 * non-0          if error
 ***********************************************************************/
int getLongestCommonCstSubSeqDP(const int* firstSequence, size_t firstSequenceLength,
				const int* secondSequence, size_t secondSequenceLength,
				size_t* length, int* value);

#endif // !_SUBSEQUENCE_H_
