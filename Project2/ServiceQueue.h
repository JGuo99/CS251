/*
Project 2
Class: CS 251
Author: Jeff Guo
Due Date: March 2 @ 11:59pm
*/
#ifndef _SERVICE_QUEUE_H
#define _SERVICE_QUEUE_H

#include <iostream>
#include <vector>
#include <utility>



class ServiceQueue {

  private:
    std::vector<int> queue;
    std::vector<int> bucket;
        /** Your private data members here!
        *   (you should have NO PUBLIC data members!
        *
        * Nested private types also go here.
        * For example, if your design needs some kind of
        *   structure, you would specify it here.
        */


  public:

	/**
	 * Constructor
	 * Description: intializes an empty service queue.
	 *
	 * RUNTIME REQUIREMENT: O(1)
	 *
         * TODO
	 */
         ServiceQueue() {

         }

	/**
	 * Destructor
	 * Description:  deallocates all memory assciated
	 *   with service queue
	 *
	 * RUNTIME REQUIREMENT:  O(N_b) where N_b is the number of buzzer
	 *	IDs that have been used during the lifetime of the
	 *	service queue; in general, at any particular instant
	 *	the actual queue length may be less than N_b.
	 *
	 *	[See discussion of "re-using buzzers" below]
	 *
         * TODO
	 */
	~ServiceQueue() {

        }

	/**
	 * Function: snapshot()
         * param:  buzzers is an integer vector passed by ref
	 * Description:  populates buzzers vector with a "snapshot"
         *               of the queue as a sequence of buzzer IDs
         *
	 *
	 * RUNTIME REQUIREMENT:  O(N)  (where N is the current queue
	 *		length).
	 */
	void snapshot(std::vector<int> &buzzers) {
             buzzers.clear();   // you don't know the history of the
                                //   buzzers vector, so we had better
                                //   clear it first.
            buzzers = queue;
        }

	/**
	 * Function: length()
	 * Description:  returns the current number of
	 *    entries in the queue.
	 *
	 * RUNTIME REQUIREMENT:  O(1)
	 */
	int  length() {

             return queue.size();   // placeholder

        }

	/**
	 * Function: give_buzzer()
         * Return:   buzzer-ID (integer) assigned to the new customer.
	 * Description:  This is the "enqueue" operation.  For us
	 *    a "buzzer" is represented by an integer (starting
	 *    from zero).  The function selects an available buzzer
	 *    and places a new entry at the end of the service queue
	 *    with the selected buzer-ID.
	 *    This buzzer ID is returned.
	 *    The assigned buzzer-ID is a non-negative integer
	 *    with the following properties:
	 *
	 *       (1) the buzzer (really it's ID) is not currently
	 *         taken -- i.e., not in the queue.  (It
	 *         may have been in the queue at some previous
	 *         time -- i.e., buzzer can be re-used).
	 *	  This makes sense:  you can't give the same
	 *	  buzzer to two people!
	 *
	 *       (2) Reusable Buzzers:  A re-usable buzzer is
	 *	  a buzzer that _was_ in the queue at some previous
	 *	  time, but currently is not.
	 *
         *         REQUIREMENT:  If there is one or more reusable
         *         buzzer, you MUST return one of them; furthermore,
         *         it must be the buzzer that became reusable most
         *         MOST RECENTLY.
	 *
	 *       (3) if there are no previously-used / reusable buzzers,
         *         the SMALLEST possible buzzer-ID is used (retrieved from
         *         inventory).
	 *	    Properties in this situation (where N is the current
	 *	      queue length):
	 *
	 *		- The largest buzzer-ID used so far is N-1
	 *
	 *		- All buzzer-IDs in {0..N-1} are in the queue
	 *			(in some order).
	 *
	 *		- The next buzzer-ID (from the basement) is N.
	 *
	 *    In other words, you can always get more buzzers (from
	 *    the basement or something), but you don't fetch an
	 *    additional buzzer unless you have to (i.e., no reusable buzzers).
	 *
	 * Comments/Reminders:
	 *
	 *	Rule (3) implies that when we start from an empty queue,
	 *	the first buzzer-ID will be 0 (zero).
	 *
	 *	Rule (2) does NOT require that the _minimum_ reuseable
	 *	buzzer-ID be used.  If there are multiple reuseable buzzers,
	 *	any one of them will do.
	 *
	 *	Note the following property:  if there are no re-useable
	 *	buzzers, the queue contains all buzzers in {0..N-1} where
	 *       N is the current queue length (of course, the buzzer IDs
	 *	may be in any order.)
	 *
	 * RUNTIME REQUIREMENT:  O(1)  ON AVERAGE or "AMORTIZED"
	 *          In other words, if there have been M calls to
	 *		give_buzzer, the total time taken for those
	 *		M calls is O(M).
	 *
	 *		An individual call may therefore not be O(1) so long
	 *		as when taken as a whole they average constant time.
	 *
	 */
	int  give_buzzer() {
    int newB;
    //checking to see if there are reusuable buzzer
    if(bucket.size() != 0){
      newB = bucket.back(); //this shows the last element in the bucket vector;
      bucket.pop_back(); //this will remove last elemnt and also decrease vector size by 1;
    }else{
      newB = queue.size();
    }
    //newB = queue.push_back(newB); // O(n) if reallocation occurs;
    //check if the vector is full, if it is increase the capacity
    if(queue.size() == queue.capacity()){
      queue.reserve(10000); //this should make reallocation faster
    }
    //since we check the capacity before hand push_back should never need to reallocate
    queue.push_back(newB);
    return newB;  // placeholder
  }


	/**
	 * function: seat()
	 * description:  if the queue is non-empty, it removes the first
	 *	 entry from (front of queue) and returns the
	 *	 buzzer ID.
	 *	 Note that the returned buzzer can now be re-used.
	 *
	 *	 If the queue is empty (nobody to seat), -1 is returned to
	 *	 indicate this fact.
         *
         * Returns:  buzzer ID of dequeued customer, or -1 if queue is empty.
	 *
	 * RUNTIME REQUIREMENT:  O(1)
	 */
	int seat() {
    int seated;

    //check if the queue is empty
    if(queue.size() == 0){
      return -1;
    }else{
      seated = queue[0]; //this should seat the first in line which is at index 0
      queue.erase(queue.begin()); //remove the first element while keeping the order
      //the best i could do was O(1) but it doesn't keep the order
      //int last = queue.back();
      //queue[seated, last] = queue[last, seated];
      //queue.pop_back();
      if(bucket.size() == bucket.capacity()){
        bucket.reserve(10000); //this should make reallocation faster
      }
      bucket.push_back(seated);
      return seated;  // placeholder
    }
  }

private:
  static int check(std::vector<int> &v, int x){
    for(int i = 0; i<v.size(); i++) {
        if(v[i]==x)
            return i;
    }
    return -1;
  }

  static void slide_left(std::vector<int> &vec, int idx){
      int n=vec.size();
      for(int i=idx; i<n-1; i++)
          vec[i]=vec[i+1];
      vec.pop_back();
  }

public:

	/**
	 * function: kick_out()
	 *
	 * description:  Some times buzzer holders cause trouble and
	 *		a bouncer needs to take back their buzzer and
	 *		tell them to get lost.
	 *
	 *		Specifially:
	 *
	 *		If the buzzer given by the 2nd parameter is
	 *		in the queue, the buzzer is removed (and the
	 *		buzzer can now be re-used) and 1 (one) is
	 *		returned (indicating success).
	 *
	 * Return:  If the buzzer isn't actually currently in the
	 *		queue, the queue is unchanged and false is returned
	 *		(indicating failure).  Otherwise, true is returned.
	 *
	 * RUNTIME REQUIREMENT:  O(1)
	 */
	bool kick_out(int buzzer) {
    // std::vector<int>::iterator pos;
    // pos = find(queue.begin(), queue.end(), buzzer);
    int pos;
    pos = check(queue, buzzer);
    //check for the position in the vector
    if(pos == -1){
      return false;
    }else{
      //this doesn't work! Spend at least few hours on this problem but couldn't figure it out
      //queue.erase(queue.begin() + pos); //delete the element at that index
      //therefore, I have to use the slow implementation to get other function to run for the time
      slide_left(queue, pos); //only for this
      if(bucket.size() == bucket.capacity()){
        bucket.reserve(10000); //this should make reallocation faster
      }
      bucket.push_back(buzzer);
      return true;
    }

  }

	/**
	 * function:  take_bribe()
	 * description:  some people just don't think the rules of everyday
	 *		life apply to them!  They always want to be at
	 *		the front of the line and don't mind bribing
	 *		a bouncer to get there.
	 *
	 *	        In terms of the function:
	 *
	 *		  - if the given buzzer is in the queue, it is
	 *		    moved from its current position to the front
	 *		    of the queue.  1 is returned indicating success
	 *		    of the operation.
	 *		  - if the buzzer is not in the queue, the queue
	 *		    is unchanged and 0 is returned (operation failed).
	 *
	 * Return:  If the buzzer isn't actually currently in the
	 *		queue, the queue is unchanged and false is returned
	 *		(indicating failure).  Otherwise, true is returned.
	 *
	 * RUNTIME REQUIREMENT:  O(1)
	 */
	bool take_bribe(int buzzer) {
    //For some reason I can get my indend code to run so I have to use the "find"
    //helper function for other file.
    //std::vector<int>::iterator it;
    // auto it = find(queue.begin(), queue.end(), buzzer);
    // int pos = std::distance(queue.begin(), it);
    int pos;
    pos = check(queue, buzzer);
    if(pos == -1){
      return false;
    }else{
      int front;
      front = queue[0];
      //switch with the index 0 place, this will cause it to be in front
      queue[pos, front] = queue[front, pos];
      return true;
    }
  }

};   // end ServiceQueue class

#endif
