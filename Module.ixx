#include<stdio.h>
void annoucement(int a, int b, int c)
{
	printf("电梯所在层数%d\n", a);
	printf("电梯人数%d\n", b);
	printf("电梯运行时间%d\n", c);
}
int max(int a[])
{
	int length, max, i;
	length = 10;
	max = a[0];
	for (i = 0; i <= length; i++)
	{
		if (a[i] > max)
			max = a[i];
	}
	return max;
}
int min(int a[])
{
	int length, min, i;
	length = 10;
	min = a[0];
	for (i = 0; i <= length; i++)
	{
		if (a[i] < min)
			min = a[i];
	}
	return min;
}
int main(void)
{
	int time = 0, number, elevator = 1, i, a, b, number_now = 0, judgement = 1;
	printf("请输入要进入电梯的人数\n");
	scanf_s("%d", &number);
int enter[15] = { 0 };
	int entrance[15] = { 0 };
	int direction[15] = { 0 };
	int situation[15] = { 0 };
	for (i = 1; i <= number; i++)
	{
		printf("从哪里上电梯\n");
		scanf_s("%d", &a);
		enter[i] = a;
		printf("从哪里下电梯\n");
		scanf_s("%d", &b);
		entrance[i] = b;
		direction[i] = entrance[i] - enter[i];
	}
	for (; judgement == 1;)   //电梯往上第一次运行的循环
	{
		if (number_now < 4)
		{
			for (i = 1; i <= number; i++)
			{
				if (elevator == enter[i] && direction[i] > 0)
				{
					number_now = number_now + 1;
					enter[i] = 0;
					situation[i] = 1;
				}
				if (elevator == entrance[i] && direction[i] > 0&& situation[i]!=0)
				{
					number_now = number_now - 1;
					entrance[i] = direction[i] = 0;
					situation[i] = 0;
				}
			}
		}
		if (number_now >= 4)
		{
			for (i = 1; i <= number; i++)
			{
				if (elevator == entrance[i] && direction[i] > 0 && enter[i] == 0 && situation[i] != 0)
				{
					number_now = number_now - 1;
					entrance[i] = direction[i] = situation[i]=0;
				}
			}
		}
		if ( elevator <= max(enter))
		{
			if (number_now < 4)
			{
				for (i = 1; i <= number; i++)
				{
					if (elevator == enter[i] && direction[i] < 0 && max(situation) == 0)
					{
						number_now = number_now + 1;
						enter[i] = 0;
						situation[i] = -1;
					}
				}
			}
			if (number_now >= 4&&max(situation)==0)
			{
				break;
			}
		}
		if (elevator > max(enter) && max(situation) == 0)
		{
			annoucement(elevator, number_now, time);
			break;
		}
		if (number_now == 0 && max(direction) == 0&&min(direction)==0)
		{
			annoucement(elevator, number_now, time);
			break;
		}
		if (elevator == 10)
		{
			break;
		}
		annoucement(elevator, number_now, time);
		elevator = elevator + 1;
		time = time + 1;
	}
	for (; judgement == 1;)   //电梯往下第一次运行的循环
	{
		if (number_now < 4)
		{
			for (i = 1; i <= number; i++)
			{
				if (elevator == enter[i] && direction[i] < 0)
				{
					number_now = number_now + 1;
					enter[i] = 0;
					situation[i] = -1;
				}
				if (elevator == entrance[i] && direction[i] < 0 && situation[i] != 0)
				{
					number_now = number_now - 1;
					entrance[i] = direction[i] = 0;
					situation[i] = 0;
				}
			}
		}
		if (number_now >= 4)
		{
			for (i = 1; i <= number; i++)
			{
				if (elevator == entrance[i] && direction[i] < 0 && enter[i] == 0 && situation[i] != 0)
				{
					number_now = number_now - 1;
					entrance[i] = direction[i] = 0;
					situation[i] = 0;
				}
			}
		}
		if (elevator >= min(enter))
		{
			if (number_now < 4)
			{
				for (i = 1; i <= number; i++)
				{
					if (elevator == enter[i] && direction[i] > 0 && min(situation) == 0)
					{
						number_now = number_now + 1;
						enter[i] = 0;
						situation[i] = 1;
					}
				}
			}
			if (number_now >= 4&&min(situation)==0)
			{
				break;
			}
		}
		if (elevator <= min(enter)&&min(situation) == 0)
		{
			annoucement(elevator, number_now, time);
			break;
		}
		if (number_now == 0 && max(direction)==0&&min(direction)==0)
		{
			annoucement(elevator, number_now, time);
			break;
		}
		if (elevator == 1)
		{
			break;
		}
		annoucement(elevator, number_now, time);
		elevator = elevator -1;
		time = time + 1;
	}
	for (; judgement == 1;)   //电梯往上第二次运行的循环
	{
		if (number_now < 4)
		{
			for (i = 1; i <= number; i++)
			{
				if (elevator == enter[i] && direction[i] > 0)
				{
					number_now = number_now + 1;
					enter[i] = 0;
					situation[i] = 1;
				}
				if (elevator == entrance[i] && direction[i] > 0 && situation[i] != 0)
				{
					number_now = number_now - 1;
					entrance[i] = direction[i] = 0;
					situation[i] = 0;
				}
			}
		}
		if (number_now >= 4)
		{
			for (i = 1; i <= number; i++)
			{
				if (elevator == entrance[i] && direction[i] > 0 && enter[i] == 0 && situation[i] != 0)
				{
					number_now = number_now - 1;
					entrance[i] = direction[i] = 0;
					situation[i] = 0;
				}
			}
		}
		if (max(direction) == 0 && elevator <= max(enter))
		{
			if (number_now < 4)
			{
				for (i = 1; i <= number; i++)
				{
					if (elevator == enter[i] && direction[i] < 0&&max(situation)==0)
					{
						number_now = number_now + 1;
						enter[i] = 0;
						situation[i] = -1;
					}
				}
			}
			if (number_now >= 4 && max(situation) == 0)
			{
				break;
			}
		}
		if ((elevator > max(enter)) && max(situation) == 0)
		{
			annoucement(elevator, number_now, time);
			break;
		}
		if (number_now == 0 && max(direction) == 0 && min(direction) == 0)
		{
			annoucement(elevator, number_now, time);
			break;
		}
		if (elevator == 10)
		{
			break;
		}
		annoucement(elevator, number_now, time);
		elevator = elevator + 1;
		time = time + 1;
	}
	for (; judgement == 1;)   //电梯往下第二次运行的循环
	{
		if (number_now < 4)
		{
			for (i = 1; i <= number; i++)
			{
				if (elevator == enter[i] && direction[i] < 0)
				{
					number_now = number_now + 1;
					enter[i] = 0;
					situation[i] = -1;
				}
				if (elevator == entrance[i] && direction[i] < 0 && situation[i] != 0)
				{
					number_now = number_now - 1;
					entrance[i] = direction[i] = 0;
					situation[i] = 0;
				}
			}
		}
		if (number_now >= 4)
		{
			for (i = 1; i <= number; i++)
			{
				if (elevator == entrance[i] && direction[i] < 0 && enter[i] == 0 && situation[i] != 0)
				{
					number_now = number_now - 1;
					entrance[i] = direction[i] = 0;
					situation[i] = 0;
				}
			}
		}
		if (elevator >= min(enter))
		{
			if (number_now < 4)
			{
				for (i = 1; i <= number; i++)
				{
					if (elevator == enter[i] && direction[i] > 0 && min(situation) == 0)
					{
						number_now = number_now + 1;
						enter[i] = 0;
						situation[i] = 1;
					}
				}
			}
			if (number_now >= 4 && min(situation) == 0)
			{
				break;
			}
		}
		if (elevator <= min(enter) && min(situation) == 0)
		{
			annoucement(elevator, number_now, time);
			break;
		}
		if (number_now == 0 && max(direction) == 0 && min(direction) == 0)
		{
			annoucement(elevator, number_now, time);
			break;
		}
		if (elevator == 1)
		{
			break;
		}
		annoucement(elevator, number_now, time);
		elevator = elevator - 1;
		time = time + 1;
	}
}


   
    
