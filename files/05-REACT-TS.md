# ⚛️ Part 5 — React with TypeScript

> Tumhara React frontend properly type karna

---

## 5.1 Setup

```bash
# Naya project
npx create-react-app my-app --template typescript

# Existing project mein add karo
npm install -D typescript @types/react @types/react-dom
```

Files ka extension:
- `.js` → `.ts`
- `.jsx` → `.tsx` (JSX wali files)

---

## 5.2 Component Props Typing

```tsx
// ===== Basic Props =====

interface ButtonProps {
  label: string
  onClick: () => void
  disabled?: boolean
  variant?: 'primary' | 'secondary' | 'danger'
}

const Button = ({ label, onClick, disabled = false, variant = 'primary' }: ButtonProps) => {
  return (
    <button
      onClick={onClick}
      disabled={disabled}
      className={`btn btn-${variant}`}
    >
      {label}
    </button>
  )
}

// ===== Children Props =====

interface CardProps {
  title: string
  children: React.ReactNode   // koi bhi JSX/text/number
}

const Card = ({ title, children }: CardProps) => {
  return (
    <div className="card">
      <h2>{title}</h2>
      <div>{children}</div>
    </div>
  )
}

// ===== React.FC — Optional but common =====

const Heading: React.FC<{ text: string }> = ({ text }) => {
  return <h1>{text}</h1>
}

// NOTE: React.FC automatically children add karta tha pehle
// Ab children explicitly likhna padta hai — isliye simple props prefer karo
```

---

## 5.3 useState Typing

```tsx
import { useState } from 'react'

interface User {
  id: number
  name: string
  email: string
}

const UserProfile = () => {
  // ===== Basic state =====
  const [count, setCount] = useState<number>(0)
  const [name, setName] = useState<string>('')
  const [isLoading, setIsLoading] = useState<boolean>(false)

  // ===== Object state =====
  const [user, setUser] = useState<User | null>(null)

  // ===== Array state =====
  const [users, setUsers] = useState<User[]>([])

  // ===== Update karna =====
  const addUser = (newUser: User) => {
    setUsers(prev => [...prev, newUser])
  }

  const updateUserName = (id: number, newName: string) => {
    setUsers(prev =>
      prev.map(u => u.id === id ? { ...u, name: newName } : u)
    )
  }

  return (
    <div>
      {isLoading ? <p>Loading...</p> : null}
      {user ? <p>{user.name}</p> : <p>No user</p>}
    </div>
  )
}
```

---

## 5.4 useEffect Typing

```tsx
import { useState, useEffect } from 'react'

interface Post {
  id: number
  title: string
  body: string
}

const PostList = () => {
  const [posts, setPosts] = useState<Post[]>([])
  const [loading, setLoading] = useState<boolean>(true)
  const [error, setError] = useState<string | null>(null)

  useEffect(() => {
    const fetchPosts = async (): Promise<void> => {
      try {
        setLoading(true)
        const res = await fetch('/api/posts')
        
        if (!res.ok) {
          throw new Error('Posts fetch nahi hue')
        }
        
        const data: Post[] = await res.json()
        setPosts(data)
      } catch (err) {
        setError(err instanceof Error ? err.message : 'Kuch gadbad hai')
      } finally {
        setLoading(false)
      }
    }

    fetchPosts()
  }, [])

  if (loading) return <div>Loading...</div>
  if (error) return <div>Error: {error}</div>

  return (
    <ul>
      {posts.map(post => (
        <li key={post.id}>{post.title}</li>
      ))}
    </ul>
  )
}
```

---

## 5.5 Event Handling Typing

```tsx
// ===== Ye sabse common confusion hai TS + React mein =====

const FormExample = () => {
  const [value, setValue] = useState('')

  // Input change
  const handleChange = (e: React.ChangeEvent<HTMLInputElement>): void => {
    setValue(e.target.value)
  }

  // Textarea
  const handleTextarea = (e: React.ChangeEvent<HTMLTextAreaElement>): void => {
    console.log(e.target.value)
  }

  // Select
  const handleSelect = (e: React.ChangeEvent<HTMLSelectElement>): void => {
    console.log(e.target.value)
  }

  // Form submit
  const handleSubmit = (e: React.FormEvent<HTMLFormElement>): void => {
    e.preventDefault()
    console.log('Submitted:', value)
  }

  // Button click
  const handleClick = (e: React.MouseEvent<HTMLButtonElement>): void => {
    console.log('Clicked')
  }

  // Key press
  const handleKeyDown = (e: React.KeyboardEvent<HTMLInputElement>): void => {
    if (e.key === 'Enter') {
      console.log('Enter pressed')
    }
  }

  return (
    <form onSubmit={handleSubmit}>
      <input
        value={value}
        onChange={handleChange}
        onKeyDown={handleKeyDown}
      />
      <button type="submit" onClick={handleClick}>Submit</button>
    </form>
  )
}
```

---

## 5.6 Custom Hooks Typing

```tsx
// ===== useLocalStorage hook =====

function useLocalStorage<T>(key: string, initialValue: T) {
  const [storedValue, setStoredValue] = useState<T>(() => {
    try {
      const item = window.localStorage.getItem(key)
      return item ? JSON.parse(item) : initialValue
    } catch {
      return initialValue
    }
  })

  const setValue = (value: T) => {
    setStoredValue(value)
    window.localStorage.setItem(key, JSON.stringify(value))
  }

  return [storedValue, setValue] as const  // 'as const' zaroori hai tuple ke liye
}

// Use karo:
const [theme, setTheme] = useLocalStorage<'light' | 'dark'>('theme', 'light')

// ===== useFetch hook =====

interface FetchState<T> {
  data: T | null
  loading: boolean
  error: string | null
}

function useFetch<T>(url: string): FetchState<T> {
  const [state, setState] = useState<FetchState<T>>({
    data: null,
    loading: true,
    error: null
  })

  useEffect(() => {
    fetch(url)
      .then(res => res.json())
      .then((data: T) => setState({ data, loading: false, error: null }))
      .catch(err => setState({ data: null, loading: false, error: err.message }))
  }, [url])

  return state
}

// Use karo:
const { data, loading, error } = useFetch<User[]>('/api/users')
```

---

## 5.7 Context API Typing

```tsx
import { createContext, useContext, useState, ReactNode } from 'react'

interface AuthContextType {
  user: User | null
  login: (email: string, password: string) => Promise<void>
  logout: () => void
  isLoggedIn: boolean
}

// Context banao — default value
const AuthContext = createContext<AuthContextType | undefined>(undefined)

// Provider
export const AuthProvider = ({ children }: { children: ReactNode }) => {
  const [user, setUser] = useState<User | null>(null)

  const login = async (email: string, password: string): Promise<void> => {
    // API call karo
    const fakeUser: User = { id: 1, name: 'Rahul', email }
    setUser(fakeUser)
  }

  const logout = (): void => {
    setUser(null)
  }

  return (
    <AuthContext.Provider value={{ user, login, logout, isLoggedIn: !!user }}>
      {children}
    </AuthContext.Provider>
  )
}

// Custom hook — clean usage
export const useAuth = (): AuthContextType => {
  const context = useContext(AuthContext)
  if (!context) {
    throw new Error('useAuth must be used within AuthProvider')
  }
  return context
}

// Component mein use karo:
const Navbar = () => {
  const { user, logout, isLoggedIn } = useAuth()
  
  return (
    <nav>
      {isLoggedIn ? (
        <>
          <span>Hello, {user?.name}</span>
          <button onClick={logout}>Logout</button>
        </>
      ) : (
        <a href="/login">Login</a>
      )}
    </nav>
  )
}
```

---

## 5.8 Event Types Cheatsheet

```
React Event Type                    Use Case
══════════════════════════════════════════════
React.ChangeEvent<HTMLInputElement>     input change
React.ChangeEvent<HTMLTextAreaElement>  textarea change
React.ChangeEvent<HTMLSelectElement>    select change
React.FormEvent<HTMLFormElement>        form submit
React.MouseEvent<HTMLButtonElement>     button click
React.MouseEvent<HTMLDivElement>        div click
React.KeyboardEvent<HTMLInputElement>   key press
React.FocusEvent<HTMLInputElement>      focus/blur
React.DragEvent<HTMLDivElement>         drag events
```

---

## ✅ Is Part Ke Baad

- [ ] Component props type kar sakta hoon
- [ ] `useState` properly type kar sakta hoon
- [ ] Event handlers confidently type kar sakta hoon
- [ ] Custom hook bana sakta hoon generics ke saath
- [ ] Context API properly typed hai
