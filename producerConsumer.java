// producer consumer problem

package com.himanshu.tomar;

import java.util.*;

public class Generate{
	public static void main(String[] args) throws InterruptException{
		final PC pc = new PC();
		Thread t1 = new Thread(new Runnable(){
			public void run(){
				try{
					pc.produce();
				}catch(InterruptException ie){
					ie.printStackTrace();
				}
			}
		});
		Thread t2 = new Thread(new Runnable(){
			public void run(){
				try{
					pc.consume();
				}catch(InterruptException ie){
					ie.printStackTrace();
				}
			}
		});
		t1.start();
		t2.start();

		t1.join();
		t2.join();
	}

	public class PC{
		
		LinkedList<Integer> list = new LinkedList<>();
		int capacity == 2;
		public void produce(){
			int value = 0;
			while(true){
				synchronized(this){
					while(list.size()==capacity)
						wait();
					list.add(value++);
					notify();

					Thread.sleep();
				}
			}
		}
		public void consume(){
			synchronized(this){
				while(list.size()==0) 
					wait();
				int value = list.removeFirst();
				System.out.println("Consumer consumed this "+value);
				notify();
				Thread.sleep();
			}
		}
	}
}