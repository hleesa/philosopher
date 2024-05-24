# 철학자들 (Philosophers)

## 소개
이 프로젝트에서는 프로세스의 스레딩 기본 개념을 배우게 됩니다. 스레드를 생성하는 방법과 뮤텍스를 사용하는 방법을 학습하게 될 것입니다.

## 프로그램 실행

```bash
git clone https://github.com/hleesa/philosopher.git
```
```bash
cd philosopher/philo
make
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```
```bash
./philo 4 310 200 100
```

## 기본 규칙
- 프로젝트는 C 언어로 작성해야 합니다.
- 함수는 예상치 않게 종료(세그멘테이션 폴트, 버스 에러, 더블 프리 등)되지 않아야 합니다. 그렇지 않으면 프로젝트는 비기능적인 것으로 간주되어 평가에서 0점을 받습니다.
- 모든 힙 할당 메모리 공간은 필요할 때 적절히 해제해야 합니다. 메모리 릭은 허용되지 않습니다.
- Makefile을 제출해야 하며, 이는 소스 파일을 필요한 출력물로 컴파일해야 합니다. 컴파일 플래그로는 -Wall, -Wextra, -Werror를 사용하고, cc를 사용해야 하며, Makefile은 재링크를 하지 않아야 합니다.
- Makefile은 최소한 $(NAME), all, clean, fclean, re 규칙을 포함해야 합니다.
- 보너스 파트를 제출하려면 Makefile에 보너스 규칙을 포함해야 하며, 이는 본 프로젝트의 메인 파트에서 금지된 다양한 헤더, 라이브러리 또는 함수를 추가하는 규칙입니다. 보너스는 _bonus.{c/h} 파일에 포함되어야 합니다. 필수 파트와 보너스 파트 평가는 별도로 이루어집니다.

## 프로젝트 개요
- 한 명 이상의 철학자가 원탁에 앉습니다.
- 테이블 중앙에 큰 스파게티 그릇이 있습니다.
- 철학자는 번갈아 가며 먹고, 생각하고, 잠을 잡니다.
- 철학자가 먹을 때는 생각하거나 잠을 자지 않고, 생각할 때는 먹거나 자지 않으며, 잠을 잘 때는 먹거나 생각하지 않습니다.
- 철학자 사이에는 포크가 있습니다. 철학자 수만큼 포크가 있습니다.
- 철학자는 오른쪽과 왼쪽 포크를 들어야만 먹을 수 있습니다.
- 철학자가 식사를 마치면 포크를 테이블에 내려놓고 잠을 잡니다. 깨어나면 다시 생각을 시작합니다. 철학자가 굶어 죽으면 시뮬레이션이 종료됩니다.
- 모든 철학자는 먹어야 하며, 굶어 죽어서는 안 됩니다.
- 철학자들은 서로 대화하지 않습니다.
- 철학자들은 다른 철학자가 죽어가고 있는지 알지 못합니다.
- 철학자는 죽지 않도록 해야 합니다.

## 글로벌 규칙
- 전역 변수는 금지됩니다.
- 프로그램은 다음 인수를 받아야 합니다:
  - `number_of_philosophers`: 철학자 수이자 포크 수.
  - `time_to_die` (밀리초): 철학자가 마지막 식사 후 또는 시뮬레이션 시작 후 `time_to_die` 밀리초 내에 먹지 않으면 죽습니다.
  - `time_to_eat` (밀리초): 철학자가 식사하는 데 걸리는 시간. 이 시간 동안 두 개의 포크를 들어야 합니다.
  - `time_to_sleep` (밀리초): 철학자가 자는 데 걸리는 시간.
  - `number_of_times_each_philosopher_must_eat` (선택 사항): 모든 철학자가 최소 `number_of_times_each_philosopher_must_eat` 번 먹으면 시뮬레이션이 종료됩니다. 지정되지 않은 경우, 철학자가 죽으면 시뮬레이션이 종료됩니다.

- 각 철학자는 1번부터 `number_of_philosophers`번까지 번호가 매겨집니다.
- 철학자 1번은 `number_of_philosophers`번 철학자 옆에 앉습니다. 나머지 철학자 번호 N은 `N-1`과 `N+1` 사이에 앉습니다.

### 로그 규칙
- 철학자의 상태 변화는 다음과 같은 형식으로 기록되어야 합니다:
  - `timestamp_in_ms X has taken a fork`
  - `timestamp_in_ms X is eating`
  - `timestamp_in_ms X is sleeping`
  - `timestamp_in_ms X is thinking`
  - `timestamp_in_ms X died`
- `timestamp_in_ms`는 현재 밀리초 단위의 타임스탬프로 대체되고, `X`는 철학자 번호로 대체됩니다.
- 출력된 상태 메시지는 다른 메시지와 혼합되어서는 안 됩니다.
- 철학자가 죽음을 알리는 메시지는 실제 죽음 후 10ms 이내에 표시되어야 합니다.
- 철학자는 죽지 않도록 해야 합니다.
- 프로그램은 데이터 레이스가 없어야 합니다.

## 필수 파트
- 프로그램 이름: `philo`
- 제출 파일: Makefile, *.h, *.c (디렉터리: `philo/`)
- Makefile 규칙: `NAME`, `all`, `clean`, `fclean`, `re`
- 허용된 외부 함수: `memset`, `printf`, `malloc`, `free`, `write`, `usleep`, `gettimeofday`, `pthread_create`, `pthread_detach`, `pthread_join`, `pthread_mutex_init`, `pthread_mutex_destroy`, `pthread_mutex_lock`, `pthread_mutex_unlock`
- 라이브러리 사용: `libft` 사용 불가
- 설명: 철학자는 각각 스레드여야 합니다. 각 철학자는 왼쪽과 오른쪽에 하나씩 포크를 가지고 있습니다. 철학자가 포크를 복제하지 않도록 각 포크의 상태는 뮤텍스로 보호되어야 합니다.

## 보너스 파트
- 프로그램 이름: `philo_bonus`
- 제출 파일: Makefile, *.h, *.c (디렉터리: `philo_bonus/`)
- Makefile 규칙: `NAME`, `all`, `clean`, `fclean`, `re`
- 허용된 외부 함수: `memset`, `printf`, `malloc`, `free`, `write`, `fork`, `kill`, `exit`, `pthread_create`, `pthread_detach`, `pthread_join`, `usleep`, `gettimeofday`, `waitpid`, `sem_open`, `sem_close`, `sem_post`, `sem_wait`, `sem_unlink`
- 라이브러리 사용: `libft` 사용 불가
- 설명: 모든 포크는 테이블 중앙에 배치됩니다. 포크 상태는 메모리에 저장되지 않으며, 사용 가능한 포크 수는 세마포어로 표현됩니다. 각 철학자는 프로세스여야 하지만, 메인 프로세스는 철학자가 아니어야 합니다.
